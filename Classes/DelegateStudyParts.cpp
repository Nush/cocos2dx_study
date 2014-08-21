#include "DelegateStudyParts.h"
bool DelegateStudyParts::init()
{
    if(!CCLayer::init()){
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMenuItemImage* btn1 = CCMenuItemImage::create("button01.png","button02.png", this,menu_selector(DelegateStudyParts::btn1Touched));
    btn1->setPosition(ccp(visibleSize.width-btn1->getContentSize().width, btn1->getContentSize().height));

    CCMenu* menu = CCMenu::create(btn1,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    return true;
}
void DelegateStudyParts::btn1Touched()
{
    if(m_delegate != NULL){
        this->m_delegate->onBtnTouched("btn1");
    }
}
void DelegateStudyParts::btn2Touched()
{
    if(m_delegate != NULL){
        this->m_delegate->onBtnTouched("btn2");
    }
}