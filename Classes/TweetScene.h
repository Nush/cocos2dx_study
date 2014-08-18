#ifndef __cocos2d_study__TweetScene__
#define __cocos2d_study__TweetScene__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class TweetScene : public CCLayer
{
public :
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(TweetScene);

private:
    void tweet();
};

#endif /* defined(__cocos2d_study__TweetScene__) */
