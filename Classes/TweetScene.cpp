#include "TweetScene.h"
#include "NativeTwitter.h"
CCScene* TweetScene::scene()
{
    CCScene* scene = CCScene::create();
    TweetScene* layer = TweetScene::create();
    scene->addChild(layer);
    return scene;
}
bool TweetScene::init()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSize editBoxSize = CCSizeMake(visibleSize.width/2, 50);
    CCEditBox* editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("9patch.png"));
    editBox->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    editBox->setFontColor(ccWHITE);
    editBox->setPlaceHolder("TextBox");
    editBox->setReturnType(kKeyboardReturnTypeDone);
    editBox->setTag(1);
    this->addChild(editBox);
    
    CCLabelTTF* tweetLabel = CCLabelTTF::create("つぶやく", "arial", 48);
    CCMenuItemLabel* tweetItem = CCMenuItemLabel::create(tweetLabel, this, menu_selector(TweetScene::tweet));
    tweetItem->setPosition(ccp(visibleSize.width/2,visibleSize.height-tweetLabel->getContentSize().height));
    
    CCMenu* tweetMenu = CCMenu::create(tweetItem,NULL);
    tweetMenu->setPosition(CCPointZero);
    this->addChild(tweetMenu);
    return true;
}
void TweetScene::tweet(){
    CCEditBox* tweetText = (CCEditBox*)this->getChildByTag(1);
    NativeTwitter::openTweetDialog(tweetText->getText());
}