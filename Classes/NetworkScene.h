#ifndef __cocos2d_study__NetworkScene__
#define __cocos2d_study__NetworkScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

#endif /* defined(__cocos2d_study__NetworkScene__) */
class NetworkScene : public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(NetworkScene);
    
    // ボタンのコールバック
    void startHttpRequest();
    
    // HttpRequestのコールバックを受け取ります
    void getCallBack(cocos2d::extension::CCHttpClient* sender, cocos2d::extension::CCHttpResponse* response);
    void postCallBack(cocos2d::extension::CCHttpClient* sender, cocos2d::extension::CCHttpResponse* response);
};
