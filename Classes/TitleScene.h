#ifndef __cocos2d_study__TitleScene__
#define __cocos2d_study__TitleScene__

#include "cocos2d.h"
class Title : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Title);
    
    // タッチの開始、移動中、終了時に呼ばれる
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved (cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__cocos2d_study__TitleScene__) */
