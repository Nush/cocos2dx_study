#ifndef __cocos2d_study__DelegateStudyScene__
#define __cocos2d_study__DelegateStudyScene__

#include "cocos2d.h"
#include "StudyDelegate.h"
USING_NS_CC;
class DelegateStudyScene : public CCLayer, public StudyDelegate
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(DelegateStudyScene);
    
    // delegateメソッド
    virtual void onBtnTouched(const char * msg);
    
    void imageBtnToudhedCallback(CCObject* sender);
    void scallAction(CCObject* sender);
};

#endif /* defined(__cocos2d_study__DelegateStudyScene__) */
