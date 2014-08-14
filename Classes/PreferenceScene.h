#ifndef __cocos2d_study__PreferenceScene__
#define __cocos2d_study__PreferenceScene__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class Preference : public CCLayer, public CCEditBoxDelegate
{
private:
    // CCEditBoxDelegateのデリゲートメソッド
    void editBoxEditingDidBegan(CCEditBox* editBox);
    void editBoxEditingDidEnd(CCEditBox* editBox);
    void editBoxTextChanged(CCEditBox* editBox, const std::string& text);
    void editBoxReturn(CCEditBox* editBox);
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(Preference);
    void menuCloseCallback(CCObject* pSender);
};
#endif /* defined(__cocos2d_study__PreferenceScene__) */
