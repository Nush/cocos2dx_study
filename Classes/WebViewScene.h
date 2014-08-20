#ifndef __cocos2d_study__WebView__
#define __cocos2d_study__WebView__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "CCWebView.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::webview_plugin;
class WebViewScene : public CCLayerColor,public CCTableViewDataSource,public CCTableViewDelegate
{
private:
    CCWebView* m_webview;
    struct Company {
        const char* name;
        const char* ref;
        const char* ex;
        Company(const char* n, const char* r){
            this->name = n;
            this->ref = r;
            this->ex = "説明なし";
        }
        Company(const char* n, const char* r,const char* e){
            this->name = n;
            this->ref = r;
            this->ex = e;
        }
    };
    std::vector<Company> m_companies;
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(WebViewScene);
    
    virtual CCSize cellSizeForTable(CCTableView* table);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView* table,unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView* table);
    
    virtual void scrollViewDidScroll(CCScrollView * view);
    virtual void scrollViewDidZoom(CCScrollView* view);
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    
    virtual void onEnterTransitionDidFinish();
    
    void closeWebViewCallback();
};
#endif /* defined(__cocos2d_study__WebView__) */
