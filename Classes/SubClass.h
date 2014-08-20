#ifndef __cocos2d_study__SubClass__
#define __cocos2d_study__SubClass__

#include "cocos2d.h"
#include "SuperClass.h"
class SubClass : public SuperClass
{
public:
    SubClass();
    ~SubClass();
    void say();
    void move();
};
#endif /* defined(__cocos2d_study__SubClass__) */
