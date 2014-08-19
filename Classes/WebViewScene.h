#ifndef __cocos2d_study__WebView__
#define __cocos2d_study__WebView__

#include "cocos2d.h"
USING_NS_CC;
class WebViewScene : public CCLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(WebViewScene);
};
#endif /* defined(__cocos2d_study__WebView__) */
