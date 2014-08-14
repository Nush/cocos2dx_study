#include "TitleScene.h"
#include "HelloWorldScene.h"
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
    CCLabelTTF* title = CCLabelTTF::create("これはタイトルです", "arial", 96);
    title->setPosition(ccp(
        visibleSize.width/2,
        visibleSize.height - title->getContentSize().height));
    this->addChild(title);
    
    // 画像の表示
    CCSprite* logo = CCSprite::create("cocos2dx_logo.png");
    logo->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    this->addChild(logo);
    
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
