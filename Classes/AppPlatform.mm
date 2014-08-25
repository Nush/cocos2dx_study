#include "AppPlatform.h"
#include "cocoa/CCString.h"
using namespace cocos2d;
const char* AppPlatform::getAppVersion()
{
    // Objective-cを利用してバージョンを取得
    NSInteger versionInt = [[[UIDevice currentDevice] systemVersion] integerValue];
    NSString *version = [[NSString alloc] initWithFormat:@"%d",versionInt];
    if(version){
        CCString* ret = CCString::createWithFormat("%s : %s","iOS",[version UTF8String]);
        // メモリの開放
        [version release];
        return ret->getCString();
    }
    // 改善
    return "";
}
