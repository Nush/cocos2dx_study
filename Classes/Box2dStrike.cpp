#include "Box2dStrike.h"
CCScene* Box2dStrike::scene()
{
    CCScene* scene = CCScene::create();
    Box2dStrike* layer =  Box2dStrike::create();
    scene->addChild(layer);
    return scene;
}
bool Box2dStrike::init()
{
    if(!CCLayer::init()){
        return false;
    }
    
    this->setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    this->initPhysics();
    scheduleUpdate();
    
    return true;
}

void Box2dStrike::initPhysics()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    b2Vec2 gravity;
    gravity.Set(0.0f, 0.0f);
    _world = new b2World(gravity);
    
    _debugDraw = new GLESDebugDraw(PTM_RATIO);
    _world->SetDebugDraw(_debugDraw);
    _world->SetContactListener(this);
    
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    _debugDraw->SetFlags(flags);
    
    
    
    // ボール
    
    CCSprite* monster = CCSprite::create("monster1.png");
    monster->setPosition(ccp(visibleSize.width/4, visibleSize.height/4));
    monster->setScale(0.9f);
    monster->setTag(0);
    this->addChild(monster);
    
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(visibleSize.width/4/PTM_RATIO, visibleSize.height/4/PTM_RATIO);
    bodyDef.userData = monster;
    bodyDef.fixedRotation = true;
    bodyDef.linearDamping = 0.5;
    m_playerBody = _world->CreateBody(&bodyDef);
    
    b2CircleShape circle;
    circle.m_radius = 50/PTM_RATIO;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle; // 形
    fixtureDef.density = 1; // 密度
    fixtureDef.friction = 0; // 摩擦率
    fixtureDef.restitution = 0.6; // 反発係数
    
    m_playerBody->CreateFixture(&fixtureDef);
    
    // 敵
    CCSprite* boss = CCSprite::create("boss.png");
    boss->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    boss->setScale(0.8f);
    boss->setTag(100);
    this->addChild(boss);
    
    b2BodyDef bossBodyDef;
    bossBodyDef.position.Set((visibleSize.width/2+30)/PTM_RATIO, visibleSize.height/2/PTM_RATIO);
    bossBodyDef.userData = boss;
    b2Body* bossBody = _world->CreateBody(&bossBodyDef);
    
    b2BodyDef bossBodyDef2;
    bossBodyDef2.position.Set((visibleSize.width/2-60)/PTM_RATIO, (visibleSize.height/2-60)/PTM_RATIO);
    bossBodyDef2.userData = boss;
    b2Body* bossBody2 = _world->CreateBody(&bossBodyDef2);
    
    b2CircleShape bossCircle;
    bossCircle.m_radius = 100/PTM_RATIO;
    
    b2FixtureDef bossFixtureDef;
    bossFixtureDef.shape = &bossCircle;
    bossFixtureDef.density = 1;
    bossFixtureDef.friction = 0;
    bossFixtureDef.restitution = 0.7;
    bossBody->CreateFixture(&bossFixtureDef);
    
    bossCircle.m_radius = 50/PTM_RATIO;
    bossBody2->CreateFixture(&bossFixtureDef);
    
    
    
    // 形
    b2PolygonShape rect;
    rect.SetAsBox(visibleSize.width/2/PTM_RATIO, 20/PTM_RATIO);
    // 状態
    b2FixtureDef wallFixtureDef;
    wallFixtureDef.density = 0.4;
    wallFixtureDef.friction = 0.5;
    wallFixtureDef.restitution = 1;
    wallFixtureDef.shape = &rect;
    
    // bodyの定義（上下）
    b2BodyDef wallBodyDefT;
    wallBodyDefT.position.Set(visibleSize.width/2/PTM_RATIO, (visibleSize.height-10)/PTM_RATIO);
    b2Body* wallBodyT = _world->CreateBody(&wallBodyDefT);
    
    b2BodyDef wallBodyDefB;
    wallBodyDefB.position.Set(visibleSize.width/2/PTM_RATIO, 10/PTM_RATIO);
    b2Body* wallBodyB = _world->CreateBody(&wallBodyDefB);
    
    // bodyに設定
    wallBodyT->CreateFixture(&wallFixtureDef);
    wallBodyB->CreateFixture(&wallFixtureDef);
    
    
    // bodyの定義（左右）
    b2BodyDef wallBodyDefL;
    wallBodyDefL.position.Set(10/PTM_RATIO, visibleSize.height/2/PTM_RATIO);
    b2Body* wallBodyL = _world->CreateBody(&wallBodyDefL);
    
    b2BodyDef wallBodyDefR;
    wallBodyDefR.position.Set((visibleSize.width-10)/PTM_RATIO, visibleSize.height/2/PTM_RATIO);
    b2Body* wallBodyR = _world->CreateBody(&wallBodyDefR);
    
    // 形を変更
    rect.SetAsBox(20/PTM_RATIO, visibleSize.height/2/PTM_RATIO);
    
    // bodyに設定
    wallBodyL->CreateFixture(&wallFixtureDef);
    wallBodyR->CreateFixture(&wallFixtureDef);
    
    

}
void Box2dStrike::draw()
{
    CCLayer::draw();
    ccGLEnableVertexAttribs(kCCVertexAttribFlag_Position);
    kmGLPushMatrix();
    _world->DrawDebugData();
    kmGLPopMatrix();
}
void Box2dStrike::update(float dt)
{
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 10;
    int32 positionIterations = 10;
    _world->Step(timeStep, velocityIterations, positionIterations);
    
    
    for (b2Body* b = _world->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != NULL) {
            CCSprite* myActor = (CCSprite*)b->GetUserData();
            if (myActor->getTag() == 0) {
                
                myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
                myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
            }
        }
    }
}

Box2dStrike::~Box2dStrike()
{
    delete _debugDraw;
    _debugDraw = NULL;
    
    delete _world;
    _world = NULL;
}
void Box2dStrike::BeginContact(b2Contact *contact)
{
    CCLOG("call");
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();
    
    CCSprite* spriteA = (CCSprite*)bodyA->GetUserData();
    CCSprite* spriteB = (CCSprite*)bodyB->GetUserData();
    
    if(spriteA == NULL || spriteB == NULL){
        return;
    }
    
    CCJumpBy* jump = CCJumpBy::create(0.3f, ccp(0, 0), 50,1);
    
    if(spriteA->getTag() == 100 && spriteA->numberOfRunningActions() == 0){
        spriteA->runAction(jump);
    } else if(spriteB->getTag() == 100 && spriteB->numberOfRunningActions() == 0){
        spriteB->runAction(jump);
    }
    
    
}
void Box2dStrike::onEnterTransitionDidFinish()
{
    m_playerBody->ApplyForce(b2Vec2(30000,15000), m_playerBody->GetWorldCenter());
}
bool Box2dStrike::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCSprite* arrow = CCSprite::create("arrow.png");
    arrow->setAnchorPoint(ccp(0.7f,0.5f));
    m_touchPoint = pTouch->getLocation();
    arrow->setPosition(((CCSprite*)m_playerBody->GetUserData())->getPosition());
    arrow->setScaleX(0.0f);
    this->addChild(arrow,1,1);
    return true;
}
void Box2dStrike::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint currentPoint = pTouch->getLocation();
    
    float angle = CC_RADIANS_TO_DEGREES(ccpToAngle(ccpSub(currentPoint,m_touchPoint)));
    
    CCSprite* arrow = (CCSprite*)this->getChildByTag(1);
    arrow->setScaleX(currentPoint.getDistance(m_touchPoint)/150.0f);
    arrow->setRotation(angle*-1);
}
void Box2dStrike::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint currentPoint = pTouch->getLocation();
    
    this->removeChildByTag(1);
}