#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);
    
    // testBtn押下時のCallback
    void testBtnPushedCallback(CCObject* sender);
    void builderSceneCallback(CCObject* sender);
    
    // タッチの開始、移動中、終了時に呼ばれる
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif // __HELLOWORLD_SCENE_H__
