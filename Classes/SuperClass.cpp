#include "SuperClass.h"
//SuperClass::SuperClass()
//{
//    
//}
SuperClass::~SuperClass()
{
    CCLOG("SuperClass デストラクタ");

}
void SuperClass::say(){
    CCLOG("I'm SuperClass");
}