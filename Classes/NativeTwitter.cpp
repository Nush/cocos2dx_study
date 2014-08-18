#include "NativeTwitter.h"
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "jp/ac/hal/cocos2d_study"
#define TWEET "tweet"
USING_NS_CC;
void NativeTwitter::openTweetDialog(const char* $tweet)
{
    JniMethodInfo methodInfo;
    if(JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, TWEET,"(Ljava/lang/String;)V")){
        jstring str = methodInfo.env->NewStringUTF($tweet);
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID ,methodInfo.methodID,str);
        methodInfo.env->DeleteLocalRef(str);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}