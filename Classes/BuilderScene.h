#ifndef __cocos2d_study__BuilderScene2__
#define __cocos2d_study__BuilderScene2__

#include "cocos2d.h"
class BuilderScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(BuilderScene);
};

#endif /* defined(__cocos2d_study__BuilderScene2__) */
