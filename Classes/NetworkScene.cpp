#include "NetworkScene.h"
#include "spine/Json.h"
USING_NS_CC_EXT;
CCScene* NetworkScene::scene()
{
    CCScene* scene = CCScene::create();
    NetworkScene* layer = NetworkScene::create();
    scene->addChild(layer);
    return scene;
}

bool NetworkScene::init()
{
    CCLOG("init");
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLabelTTF* startHttpLabel = CCLabelTTF::create("サーバーに送信する", "arial", 48);
    
    CCMenuItemLabel* startItem = CCMenuItemLabel::create(startHttpLabel, this, menu_selector(NetworkScene::startHttpRequest));
    startItem->setPosition(ccp(visibleSize.width/2, visibleSize.height/2+startHttpLabel->getContentSize().height));
    CCMenu* startMenu = CCMenu::create(startItem,NULL);
    startMenu->setPosition(CCPointZero);
    this->addChild(startMenu);
    
    CCSize editBoxSize = CCSizeMake(visibleSize.width/2, 50);
    CCEditBox* editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("9patch.png"));
    editBox->setPosition(ccp(visibleSize.width/2, visibleSize.height/2+startHttpLabel->getContentSize().height*2));
    editBox->setFontColor(ccWHITE);
    editBox->setPlaceHolder("TextBox");
    editBox->setReturnType(kKeyboardReturnTypeDone);
    editBox->setTag(1);
    this->addChild(editBox);
    
    // サーバーとGET通信
    CCHttpRequest* req = new CCHttpRequest();
    req->setUrl("http://cocos2dx-api.herokuapp.com/tests");
    req->setRequestType(CCHttpRequest::kHttpGet);
    req->setResponseCallback(this, callfuncND_selector(NetworkScene::getCallBack));
    CCHttpClient::getInstance()->send(req);
    req->release();
    
    // サーバ通信結果用ラベル
    CCLabelTTF* reqLabel = CCLabelTTF::create("connecting", "arial", 48);
    reqLabel->setPosition(ccp(visibleSize.width/2,visibleSize.height-reqLabel->getContentSize().height));
    reqLabel->setTag(2);
    this->addChild(reqLabel);
    
    CCLabelTTF* reqLabel2 = CCLabelTTF::create("num", "arial", 48);
    reqLabel2->setPosition(ccp(visibleSize.width/2,visibleSize.height-reqLabel2->getContentSize().height*2));
    reqLabel2->setTag(3);
    this->addChild(reqLabel2);
    
    //
    CCLabelTTF* postLabel = CCLabelTTF::create("Post用 Label", "arial", 48);
    postLabel->setPosition(ccp(visibleSize.width/2,visibleSize.height/2-postLabel->getContentSize().height*2));
    postLabel->setTag(4);
    this->addChild(postLabel);
    
    
    return true;
}

void NetworkScene::getCallBack(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response)
{
    // サーバーからjsonで送られてきたデータをぱーすして表示
    std::vector<char>* data = response->getResponseData();
    std::string result(data->begin(), data->end());

    Json* json = Json_create(result.c_str());
    std::string msg = Json_getString(json, "msg", "");
    int num = Json_getInt(json, "num", 0);
    
    CCLabelTTF* reqLabel = (CCLabelTTF*)this->getChildByTag(2);
    reqLabel->setString(msg.data());
    
    CCLabelTTF* reqLabel2 = (CCLabelTTF*)this->getChildByTag(3);
    CCString* numStr = CCString::createWithFormat("%d",num);
    reqLabel2->setString(numStr->getCString());
    
    
}
/*
 ラベル押下時のコールバック
 */
void NetworkScene::startHttpRequest()
{
    // edit boxの値を送信する
    CCEditBox* editBox = (CCEditBox*)this->getChildByTag(1);
    std::string sendStr = "data=";
    sendStr+=editBox->getText();
    
    CCHttpRequest* req = new CCHttpRequest();
    req->setUrl("http://cocos2dx-api.herokuapp.com/tests");
    req->setRequestType(CCHttpRequest::kHttpPost);
    req->setResponseCallback(this, callfuncND_selector(NetworkScene::postCallBack));
    req->setRequestData(sendStr.data(), strlen(sendStr.data()));
    CCHttpClient::getInstance()->send(req);
    req->release();
}
void NetworkScene::postCallBack(cocos2d::extension::CCHttpClient *sender, cocos2d::extension::CCHttpResponse *response)
{
    // サーバーからjsonで送られてきたデータをぱーすして表示
    std::vector<char>* data = response->getResponseData();
    std::string result(data->begin(), data->end());
    
    Json* json = Json_create(result.c_str());
    std::string sendData = Json_getString(json, "data", "default");
    
    CCLabelTTF* postLabel = (CCLabelTTF*)this->getChildByTag(4);
    postLabel->setString(sendData.data());
    
}