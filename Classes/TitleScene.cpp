#include "TitleScene.h"
#include "HelloWorldScene.h"
#include "AppPlatform.h"
USING_NS_CC;
CCScene* Title::scene()
{
    CCScene *scene = CCScene::create();
    Title *layer = Title::create();
    scene->addChild(layer);
    return scene;
}
bool Title::init()
{
    // 画面サイズの取得
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // タッチの有効化
    this->setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    // 文字列の表示
    CCLabelTTF* title = CCLabelTTF::create("これはタイトルです", "arial", 64);
    title->setPosition(ccp(
        visibleSize.width/2,
        visibleSize.height - title->getContentSize().height));
    this->addChild(title);
    
    // 画像の表示
    CCSprite* logo = CCSprite::create("cocos2dx_logo.png");
    logo->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(logo);
    
    // レベル3：端末情報の取得
    // iOSはObjective-C、AndroidはJavaのJniを利用して取得
    const char* version = AppPlatform::getAppVersion();
    CCLOG("%s",version);
    CCLabelTTF* versionLabel = CCLabelTTF::create(version, "arial", 48);
    versionLabel->setPosition(ccp(visibleSize.width-versionLabel->getContentSize().width/2, versionLabel->getContentSize().height/2));
    this->addChild(versionLabel);
    
    std::cout << "a";
    
    return true;
}
bool Title::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    return true;
}
void Title::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
}
void Title::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCTransitionFade* helloTrans = CCTransitionFade::create(2.0f, HelloWorld::scene());
    CCDirector::sharedDirector()->replaceScene(helloTrans);
}
