#ifndef __cocos2d_study__AppPlatform__
#define __cocos2d_study__AppPlatform__

#include "cocos2d.h"
/*
 バージョンを取得するために処理を分ける
 共通のヘッダーファイルを作成
 */
class AppPlatform{
public:
    static const char* getAppVersion();
};
#endif /* defined(__cocos2d_study__AppPlatform__) */
