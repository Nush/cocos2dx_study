#include "PreferenceScene.h"
CCScene* Preference::scene()
{
    CCScene* scene = CCScene::create();
    
    Preference* layer = Preference::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool Preference::init()
{
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(Preference::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                pCloseItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    // データ保存用のEditText
    CCSize editBoxSize = CCSizeMake(visibleSize.width/2, 50);
    CCEditBox* editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("9patch.png"));
    editBox->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    editBox->setFontColor(ccWHITE);
    editBox->setPlaceHolder("TextBox");
    editBox->setReturnType(kKeyboardReturnTypeDone);
    editBox->setDelegate(this);
    this->addChild(editBox);
    
    
    // Preferenceからデータを取得して設定
    std::string data = CCUserDefault::sharedUserDefault()->getStringForKey("test","No Data");
    CCLabelTTF* dataLabel = CCLabelTTF::create(data.data(), "arial", 48);
    dataLabel->setPosition(ccp(visibleSize.width/2, editBox->getPositionY()+dataLabel->getContentSize().height));
    this->addChild(dataLabel);
    return true;
}

void Preference::editBoxEditingDidBegan(cocos2d::extension::CCEditBox *editBox)
{
}
void Preference::editBoxEditingDidEnd(cocos2d::extension::CCEditBox *editBox)
{
    // EditBoxのテキストを保存
    CCUserDefault* user = CCUserDefault::sharedUserDefault();
    user->setStringForKey("test", editBox->getText());
    user->flush();
}
void Preference::editBoxTextChanged(cocos2d::extension::CCEditBox *editBox, const std::string &text)
{
}
void Preference::editBoxReturn(cocos2d::extension::CCEditBox *editBox)
{
}
void Preference::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}