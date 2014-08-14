#include <jni.h>
#include "AppPlatform.h"
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "jp/ac/hal/cocos2d_study"

using namespace std;
using namespace cocos2d;

const char* AppPlatform::getAppVersion()
{
    JniMethodInfo t;
    const char* ret = NULL;
    
    if(JniHelper::getStaticMethodInfo(t,CLASS_NAME,"getAppVersionInJava","()Ljava/lang/String;")){
        jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID,t.methodID);
        
        std::string sstr = JniHelper::jstring2string(jstr);
        t.env->DeleteLocalRef(t.classID);
        t.env->DeleteLocalRef(jstr);
        CCString * cstr = CCString::create(sstr.c_str());
        ret = cstr->getCString();
    }
    
    return ret;
}