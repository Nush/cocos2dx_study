#include "SubClass.h"

//SubClass::SubClass
//{
//    CCLOG("SubClass コンストラクタ");
//}
SubClass::SubClass()
{
    CCLOG("SubClass コンストラクタ");
}
SubClass::~SubClass()
{
    CCLOG("SubClass デストラクタ");
}

void SubClass::say()
{
    CCLOG("I'm SubClass");
}
void SubClass::move()
{
    CCLOG("SubClass move");
}