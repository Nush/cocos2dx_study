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
    
    this->addChild(label);
    
    DelegateStudyParts* partsLayer = DelegateStudyParts::create();
    partsLayer->setDelegate(this);
    partsLayer->setPosition(CCPointZero);
    this->addChild(partsLayer);
    
    
    return true;
}

void DelegateStudyScene::onBtnTouched(const char *msg)
{
    CCLOG("%s",msg);
}
