#ifndef __cocos2d_study__CCBLayer__
#define __cocos2d_study__CCBLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
/*
 CocosBuildrで作成したシーンを扱うクラス
 */
class CCBLayer : public CCLayer, public CCBSelectorResolver,public CCBMemberVariableAssigner
{
public:
    CCBLayer();
private:
    CCLabelTTF* m_displayTime;
    CCLabelTTF* m_tapText;
    virtual bool init();
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    void tappedSunny(CCObject* pSender, CCControlEvent pCCControlEvent);
    void tappedRainy(CCObject* pSender, CCControlEvent pCCControlEvent);
    void updateTime();
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCBLayer, create);
};

#endif /* defined(__cocos2d_study__CCBLayer__) */
