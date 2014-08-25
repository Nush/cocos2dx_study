#ifndef __cocos2d_study__Box2dStrike__
#define __cocos2d_study__Box2dStrike__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
USING_NS_CC;

#define PTM_RATIO 32.0

class Box2dStrike : public CCLayer,public b2ContactListener
{
public:
    virtual bool init();
    virtual void draw();
    static CCScene* scene();
    CREATE_FUNC(Box2dStrike);
    
    void initPhysics();
    void update(float dt);
    ~Box2dStrike();
    
    void BeginContact(b2Contact* contact);
    void onEnterTransitionDidFinish();
    
    CCPoint m_touchPoint;
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
private:
    b2Body* m_playerBody;
    b2World *_world;
    GLESDebugDraw *_debugDraw;
};

#endif /* defined(__cocos2d_study__Box2dStrike__) */
