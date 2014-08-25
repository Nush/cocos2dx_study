#include <jni.h>
#include "AppPlatform.h"
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "jp/ac/hal/cocos2d_study"

using namespace std;
using namespace cocos2d;

const char* AppPlatform::getAppVersion()
{
    JniMethodInfo t;
    std::string ret = "";
    
    if(JniHelper::getStaticMethodInfo(t,CLASS_NAME,"getAppVersionInJava","()Ljava/lang/String;")){
        jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID,t.methodID);
        
        ret = JniHelper::jstring2string(jstr);
        CCLOG("1 %s",ret.c_str());
        t.env->DeleteLocalRef(t.classID);
        t.env->DeleteLocalRef(jstr);
    }
//    CCLOG("1 %s",ret.c_str());
    
    return ret.c_str();
}