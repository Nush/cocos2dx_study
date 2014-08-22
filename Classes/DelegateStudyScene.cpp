#include "DelegateStudyScene.h"
#include "DelegateStudyParts.h"
CCScene* DelegateStudyScene::scene()
{
    CCScene* scene = CCScene::create();
    DelegateStudyScene* layer = DelegateStudyScene::create();
    scene->addChild(layer);
    return scene;
}
bool DelegateStudyScene::init()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLabelTTF* label = CCLabelTTF::create("I'm scene", "Hiragino Kaku Gothic ProN", 48);
    label->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    label->setTag(1);
    this->addChild(label);
    
    // DelegatePartsで発火するイベントをこのクラスが受け取ります
    DelegateStudyParts* partsLayer = DelegateStudyParts::create();
    partsLayer->setDelegate(this);
    partsLayer->setPosition(CCPointZero);
    this->addChild(partsLayer);
    
    
    CCMenuItemImage* image = CCMenuItemImage::create("closeWebView.png", "closeWebView.png",this,menu_selector(DelegateStudyScene::imageBtnToudhedCallback));
    image->setPosition(ccp(visibleSize.width/2, visibleSize.height/3));
    CCMenu* menu = CCMenu::create(image,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    
    return true;
}

void DelegateStudyScene::onBtnTouched(const char *msg)
{
    std::string str = "Delegate : ";
    str+=msg;
    
    CCLabelTTF* label = (CCLabelTTF*)this->getChildByTag(1);
    label->setString(str.c_str());
    CCLOG("%s",msg);
}

void DelegateStudyScene::imageBtnToudhedCallback(CCObject* sender)
{
    CCMenuItemImage* item = dynamic_cast<CCMenuItemImage*>(sender);
    
    CCScaleTo* scale = CCScaleTo::create(0.2f, 1.5f);
    CCCallFuncN* func = CCCallFuncN::create(this, callfuncN_selector(DelegateStudyScene::scallAction));
    item->runAction(CCSequence::create(scale,func,NULL));
}
void DelegateStudyScene::scallAction(CCObject* sender)
{
    CCMenuItemImage* item = dynamic_cast<CCMenuItemImage*>(sender);
    CCScaleTo* scale = CCScaleTo::create(0.3f, 1.0f);
    item->runAction(scale);
}