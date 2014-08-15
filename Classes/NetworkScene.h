#ifndef __cocos2d_study__NetworkScene__
#define __cocos2d_study__NetworkScene__

#include "cocos2d.h"
#include "HttpRequest.h"
#include "HttpClient.h"

USING_NS_CC;

#endif /* defined(__cocos2d_study__NetworkScene__) */
class NetworkScene : public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(NetworkScene);
};
