#include "SuperClass.h"
SuperClass::SuperClass()
{
    CCLOG("SuperClass コンストラクタ");
}
SuperClass::~SuperClass()
{
    CCLOG("SuperClass デストラクタ");

}
void SuperClass::say(){
    CCLOG("I'm SuperClass");
}