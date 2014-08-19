#include "WebViewScene.h"
#include "CCWebView.h"
using namespace cocos2d::webview_plugin;
CCScene* WebViewScene::scene()
{
    CCScene* scene = CCScene::create();
    WebViewScene* layer = WebViewScene::create();
    scene->addChild(layer);
    return scene;
}

bool WebViewScene::init()
{
    CCWebView* webview = CCWebView::create();
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    webview->setRect(0, 0, visibleSize.width, visibleSize.height);
    webview->setVisibility(true);
    webview->loadUrl("http://www.applibot.co.jp/");
    
    return true;
}