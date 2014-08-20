#include "WebViewScene.h"
CCScene* WebViewScene::scene()
{
    CCScene* scene = CCScene::create();
    WebViewScene* layer = WebViewScene::create();
    scene->addChild(layer);
    return scene;
}

bool WebViewScene::init()
{
    if(!CCLayerColor::initWithColor(ccc4(255,255,255,255))){
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    
    //企業名とサイトアドレス、説明を持った構造体
    struct Company cyber("CyberAgent","https://www.cyberagent.co.jp","緑です");
    struct Company appli("Applibot","https://www.applibot.co.jp","青いです");
    
    m_companies.push_back(cyber);
    m_companies.push_back(appli);
    
    
    // テーブルビューに表示
    CCTableView* tableView = CCTableView::create(this, CCSizeMake(visibleSize.width, visibleSize.height));
    tableView->setAnchorPoint(ccp(0, 0));
    tableView->setDirection(kCCScrollViewDirectionVertical);
    tableView->setPosition(ccp(visibleSize.width*0.75,0));
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();
    
    
    // 閉じるボタン
    CCMenuItemImage* closeBtn = CCMenuItemImage::create("closeWebView.png", "closeWebView.png",this,menu_selector(WebViewScene::closeWebViewCallback));
    closeBtn->setPosition(ccp(visibleSize.width-closeBtn->getContentSize().width/2, closeBtn->getContentSize().height/2));
    CCMenu* menu = CCMenu::create(closeBtn,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,1);
    
    return true;
}
void WebViewScene::onEnterTransitionDidFinish()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    m_webview = CCWebView::create();
    m_webview->setRect(0, 0, visibleSize.width*0.75, visibleSize.height);
}

CCSize WebViewScene::cellSizeForTable(CCTableView* table) {
    return CCSize(CCDirector::sharedDirector()->getVisibleSize().width, 50);
}

CCTableViewCell* WebViewScene::tableCellAtIndex(CCTableView* table, unsigned int idx)
{
    CCTableViewCell* cell = table->dequeueCell();
    cell = new CCTableViewCell();
    cell->autorelease();
   

    CCLabelTTF* label
        = CCLabelTTF::create(m_companies[idx].name, "Hiragino Kaku Gothic ProN", 24);
    label->setAnchorPoint(ccp(0, 0));
    label->setColor(ccBLACK);
    cell->addChild(label);
    
    
    return cell;
}
// セルの数を設定する
unsigned int WebViewScene::numberOfCellsInTableView (CCTableView* table)
{
    return m_companies.size();
}

//中身の実装はなし
void WebViewScene::scrollViewDidScroll(CCScrollView* view)
{
}

//中身の実装はなし
void WebViewScene::scrollViewDidZoom(CCScrollView* view)
{
}

//中身の実装はなし
void WebViewScene::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLOG("touch at %d",cell->getIdx());
    m_webview->setVisibility(true);
    m_webview->loadUrl(m_companies[cell->getIdx()].ref);
}
void WebViewScene::closeWebViewCallback()
{
    m_webview->setVisibility(false);
}