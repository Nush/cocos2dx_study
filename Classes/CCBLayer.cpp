#include "CCBLayer.h"
#include <time.h>
USING_NS_CC;
USING_NS_CC_EXT;

CCBLayer::CCBLayer()
{
    m_displayTime = CCLabelTTF::create("", "arial", 48);
    m_tapText = CCLabelTTF::create("", "arial", 48);
}
bool CCBLayer::init()
{
    this->schedule(schedule_selector(CCBLayer::updateTime));
    return true;
}
SEL_MenuHandler CCBLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "tappedSunny", CCBLayer::tappedSunny);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "tappedRainy", CCBLayer::tappedRainy);
    return NULL;
}

void CCBLayer::tappedSunny(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("Sunny");
    m_tapText->setString("Sunny");
     m_tapText->setColor(ccRED);
}
void CCBLayer::tappedRainy(cocos2d::CCObject *pSender, CCControlEvent pCCControlEvent)
{
    CCLOG("Rainy");
    m_tapText->setString("Rainy");
    m_tapText->setColor(ccBLUE);
}
SEL_CCControlHandler CCBLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    return NULL;
}

bool CCBLayer::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "DisplayTime", CCLabelTTF*, m_displayTime);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "TapText", CCLabelTTF*, m_tapText);
    return NULL;
}
/*
 現在時刻を毎フレームアップデートします
 */
void CCBLayer::updateTime()
{
    // レベル2：現在時刻の表示
    // グリニッジ標準時を取得し、構造体tmを使って表示させる
    time_t greenwich = time(NULL);
    struct tm *now = localtime(&greenwich);
    CCString* currentTime = CCString::createWithFormat("%d:%d:%d",now->tm_hour,now->tm_min,now->tm_sec);
    m_displayTime->setString(currentTime->getCString());
}