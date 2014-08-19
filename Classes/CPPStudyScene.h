#ifndef __cocos2d_study__CPPStudyScene__
#define __cocos2d_study__CPPStudyScene__

#include "cocos2d.h"
USING_NS_CC;
class CPPStudyScene : public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(CPPStudyScene);
};

#endif /* defined(__cocos2d_study__CPPStudyScene__) */
