#ifndef __cocos2d_study__CCBLayerLoader__
#define __cocos2d_study__CCBLayerLoader__

#include "CCBLayer.h"
class CCBLayerLoader : public CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCBLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCBLayer);
};
#endif /* defined(__cocos2d_study__CCBLayerLoader__) */
