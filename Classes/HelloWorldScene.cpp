#include "HelloWorldScene.h"
#include "BuilderScene.h"
#include "PreferenceScene.h"
#include "NetworkScene.h"
#include "SQLiteScene.h"
#include "TweetScene.h"
#include "WebViewScene.h"
#include "CPPStudyScene.h"
#include "DelegateStudyScene.h"
#include "Box2dStrike.h"

USING_NS_CC;

#define FONT_SIZE 48
#define FONT_NAME "arial"

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /*-----------------------------ここより上デフォルト---------------------------------*/
    
    // タッチの有効化
    this->setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    // 文字列の表示
    CCLabelTTF* label = CCLabelTTF::create("change text", FONT_NAME, 32);
    label->setPosition(ccp(label->getContentSize().width/2, visibleSize.height/2));
    label->setTag(0);
    this->addChild(label);
    
    // 画像の表示
    CCSprite* logo = CCSprite::create("cocos2dx_logo.png");
    logo->setPosition(ccp(visibleSize.width*0.75, visibleSize.height/2));
    logo->setTag(1);
    this->addChild(logo);
    
    // レベル1: ボタンの押下で何かが起きる（Callback）
    CCMenuItemImage* testBtnItem = CCMenuItemImage::create(
                                    "button01.png",
                                    "button02.png",
                                    this,
                                                           menu_selector(HelloWorld::testBtnPushedCallback));
    testBtnItem->setPosition(ccp(
                                 visibleSize.width-testBtnItem->getContentSize().width/2,
                                 visibleSize.height-testBtnItem->getContentSize().height/2));
    CCMenu* testBtn = CCMenu::create(testBtnItem,NULL);
    testBtn->setPosition(CCPointZero);
    
    this->addChild(testBtn);
    
    
    //===================================================================================
    // Scene移動ラベル
    //===================================================================================
    
    // CocosBuilderで作成したSceneへ移動
    CCMenuItemLabel* builderBtnItem = CCMenuItemLabel::create(
                                        CCLabelTTF::create("BuilderSceneへ", FONT_NAME, FONT_SIZE),
                                        this,
                                        menu_selector(HelloWorld::sceneChangeCallback));
    builderBtnItem->setPosition(ccp(
                                    visibleSize.width/2,
                                    visibleSize.height - builderBtnItem->getContentSize().height*0.5));
    builderBtnItem->setTag(BUILDER);

    
    // Preferenceへ移動
    CCMenuItemLabel* preBtnItem = CCMenuItemLabel::create(
                                    CCLabelTTF::create("Preferenceへ", FONT_NAME, FONT_SIZE),
                                    this,
                                    menu_selector(HelloWorld::sceneChangeCallback));
    preBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - preBtnItem->getContentSize().height*1.5));
    preBtnItem->setTag(PREFERENCE);
    
    // Networkへ移動
    CCMenuItemLabel* netBtnItem = CCMenuItemLabel::create(
                                    CCLabelTTF::create("HttpRequestへ", FONT_NAME, FONT_SIZE),
                                    this,
                                    menu_selector(HelloWorld::sceneChangeCallback));
    netBtnItem->setPosition(ccp(
         visibleSize.width/2,
         visibleSize.height - netBtnItem->getContentSize().height*2.5));
    netBtnItem->setTag(NETWORK);
    
    // SQLiteへ移動
    CCMenuItemLabel* sqlBtnItem = CCMenuItemLabel::create(
                                    CCLabelTTF::create("SQLiteへ", FONT_NAME, FONT_SIZE),
                                    this,
                                    menu_selector(HelloWorld::sceneChangeCallback));
    sqlBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - sqlBtnItem->getContentSize().height*3.5));
    sqlBtnItem->setTag(SQLITE);
    
    
    // Tweetへ移動
    CCMenuItemLabel* twtBtnItem = CCMenuItemLabel::create(
                                   CCLabelTTF::create("Twitterへ", FONT_NAME, FONT_SIZE),
                                   this,
                                   menu_selector(HelloWorld::sceneChangeCallback));
    twtBtnItem->setTag(TWEET);
    twtBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - twtBtnItem->getContentSize().height*4.5));

    // WebViewへ移動
    CCMenuItemLabel* webBtnItem = CCMenuItemLabel::create(
                                    CCLabelTTF::create("WebViewへ", FONT_NAME, FONT_SIZE),
                                    this,
                                    menu_selector(HelloWorld::sceneChangeCallback));
    webBtnItem->setTag(WEBVIEW);
    webBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - webBtnItem->getContentSize().height*5.5));
    
    // CPPStudyへ移動
    CCMenuItemLabel* cppBtnItem = CCMenuItemLabel::create(
                                    CCLabelTTF::create("CPPStudyへ", FONT_NAME, FONT_SIZE),
                                    this,
                                    menu_selector(HelloWorld::sceneChangeCallback));
    cppBtnItem->setTag(CPPSTUDY);
    cppBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - cppBtnItem->getContentSize().height*6.5));
    
    // DelegateStudyScene
    CCMenuItemLabel* delBtnItem = CCMenuItemLabel::create(
                                                          CCLabelTTF::create("DelegateStudySceneへ", FONT_NAME, FONT_SIZE),
                                                          this,
                                                          menu_selector(HelloWorld::sceneChangeCallback));
    delBtnItem->setTag(DELEGATE);
    delBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - delBtnItem->getContentSize().height*7.5));
    // Box2dScene
    CCMenuItemLabel* boxBtnItem = CCMenuItemLabel::create(
                                                          CCLabelTTF::create("Box2dへ", FONT_NAME, FONT_SIZE),
                                                          this,
                                                          menu_selector(HelloWorld::sceneChangeCallback));
    boxBtnItem->setTag(BOX2D);
    boxBtnItem->setPosition(ccp(
                                visibleSize.width/2,
                                visibleSize.height - boxBtnItem->getContentSize().height*8.5));
    
    // Menu
    CCMenu* menuBtn = CCMenu::create(builderBtnItem,
                                     preBtnItem,
                                     netBtnItem,
                                     sqlBtnItem,
                                     twtBtnItem,
                                     webBtnItem,
                                     cppBtnItem,
                                     delBtnItem,
                                     boxBtnItem,
                                     NULL);
    menuBtn->setPosition(CCPointZero);
    
    this->addChild(menuBtn);
    
    return true;
}
/*
 testBtnのcallbacks
 */
void HelloWorld::testBtnPushedCallback(CCObject* sender)
{
    // レベル1:文字列の変更
    CCLabelTTF* label = (CCLabelTTF*)this->getChildByTag(0);
    label->setString("画像変更と文字列移動");
    
    // レベル1:画像や文字をを動かす（文字）
    CCMoveTo* moveAction = CCMoveTo::create(1.0f, ccp(label->getContentSize().width/2, label->getPositionY()));
    label->runAction(moveAction);
    
    // レベル1:画像の変更
    CCSprite* logo = (CCSprite*)this->getChildByTag(1);
    CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage("cocos2dx_logo2.png");
    logo->setTexture(tex);
}
void HelloWorld::sceneChangeCallback(cocos2d::CCObject *sender)
{
    // 押されたのはどれか
    CCMenuItem* item = (CCMenuItem*)sender;
    
    // transition系のスーパークラス
    CCTransitionScene* ts = NULL;
    
    // タグで判別
    switch (item->getTag()) {
        case BUILDER:
            ts = CCTransitionFade::create(2.0f, BuilderScene::scene());
            break;
        case PREFERENCE:
            ts = CCTransitionMoveInR::create(2.0f, Preference::scene());
            break;
        case NETWORK:
            ts = CCTransitionFlipY::create(0.5f, NetworkScene::scene());
            break;
        case SQLITE:
            ts = CCTransitionFlipX::create(0.5f, SQLiteScene::scene());
            break;
        case TWEET:
            ts = CCTransitionCrossFade::create(0.5f, TweetScene::scene());
            break;
        case WEBVIEW:
            ts = CCTransitionMoveInR::create(0.5f, WebViewScene::scene());
            break;
        case CPPSTUDY:
            ts = CCTransitionJumpZoom::create(0.5f, CPPStudyScene::scene());
            break;
        case DELEGATE:
            ts = CCTransitionRotoZoom::create(1.0f, DelegateStudyScene::scene());
            break;
        case BOX2D:
            ts = CCTransitionFadeDown::create(0.5f, Box2dStrike::scene());
        default:
            break;
    }
    // 繊維
    CCDirector::sharedDirector()->replaceScene(ts);

}

/*
 デフォルトのアプリ終了ボタン
 */
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

bool HelloWorld::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
    return true;
}
void HelloWorld::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
}
void HelloWorld::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    // レベル1:画像や文字をを動かす（画像）
    // タッチした位置にcocos2dxのロゴが移動します
    CCSprite* logo = (CCSprite*)this->getChildByTag(1);
    logo->stopAllActions();                             // 一回アクションを止める
    
    CCPoint touchPoint = pTouch->getLocationInView();
    touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
    float distance = ccpDistance(touchPoint, logo->getPosition());
    float duration = distance/visibleSize.width*1.5f;
    
    CCMoveTo* moveAction = CCMoveTo::create(duration, touchPoint);
    logo->runAction(moveAction);
    
}
