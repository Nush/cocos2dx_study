#ifndef __cocos2d_study__DelegateStudyParts__
#define __cocos2d_study__DelegateStudyParts__

#include "cocos2d.h"
#include "StudyDelegate.h"
USING_NS_CC;
class DelegateStudyParts : public CCLayer
{
public:
    virtual bool init();
    CREATE_FUNC(DelegateStudyParts);
    
    StudyDelegate* getDelegate(){return m_delegate;}
    void setDelegate(StudyDelegate* pDelegate){m_delegate = pDelegate;}
protected:
    StudyDelegate* m_delegate;
private:
    void btn1Touched();
    void btn2Touched();
};

#endif /* defined(__cocos2d_study__DelegateStudyParts__) */
