#include "SQLiteScene.h"
#include "SQlite/sqlite3.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

#define DB_NAME "sample.db"

CCScene* SQLiteScene::scene()
{
    CCScene* scene = CCScene::create();
    SQLiteScene* layer = SQLiteScene::create();
    scene->addChild(layer);
    return scene;
}
bool SQLiteScene::init()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // LabelとEditBoxを作成しておきます
    // editbox
    CCSize editBoxSize = CCSizeMake(visibleSize.width/5, 50);
    CCEditBox* editBoxKey = CCEditBox::create(editBoxSize, CCScale9Sprite::create("9patch.png"));
    editBoxKey->setPosition(ccp(visibleSize.width/4-editBoxKey->getContentSize().width/2, visibleSize.height/2));
    editBoxKey->setFontColor(ccWHITE);
    editBoxKey->setPlaceHolder("TextBox");
    editBoxKey->setReturnType(kKeyboardReturnTypeDone);
    editBoxKey->setTag(1);

    CCEditBox* editBoxVal = CCEditBox::create(editBoxSize, CCScale9Sprite::create("9patch.png"));
    editBoxVal->setPosition(ccp(visibleSize.width/4+editBoxVal->getContentSize().width/2, visibleSize.height/2));
    editBoxVal->setFontColor(ccWHITE);
    editBoxVal->setPlaceHolder("TextBox");
    editBoxVal->setReturnType(kKeyboardReturnTypeDone);
    editBoxVal->setTag(2);
    
    this->addChild(editBoxKey);
    this->addChild(editBoxVal);
    
    // label
    CCLabelTTF* keyLabel = CCLabelTTF::create("KEY", "arial", 48);
    keyLabel->setPosition(ccp(visibleSize.width/4-editBoxKey->getContentSize().width/2, visibleSize.height/2+keyLabel->getContentSize().height));
    CCLabelTTF* valLabel = CCLabelTTF::create("VALUE", "arial", 48);
    valLabel->setPosition(ccp(visibleSize.width/4+editBoxVal->getContentSize().width/2, visibleSize.height/2+valLabel->getContentSize().height));
    
    this->addChild(keyLabel);
    this->addChild(valLabel);
    
    CCLabelTTF* sqliteDisplayLabel = CCLabelTTF::create("", "arial", 24);
    this->addChild(sqliteDisplayLabel,0,0);

    
    CCMenuItemLabel* btnItem = CCMenuItemLabel::create(
                                                          CCLabelTTF::create("登録", "arial", 48),
                                                          this,
                                                          menu_selector(SQLiteScene::regist));
    btnItem->setPosition(ccp(
                                visibleSize.width/4,
                                btnItem->getContentSize().height));
    
    
    
    // Menu
    CCMenu* menuBtn = CCMenu::create(btnItem,NULL);
    menuBtn->setPosition(CCPointZero);
    
    this->addChild(menuBtn);
    
    // テーブル作成
    sqliteCreateTable();
    
    // DB内の一覧の表示
    reloadSQLite();
    
    return true;
}
/*
    SQLiteに接続します
 */
int SQLiteScene::sqliteOpen(sqlite3 **database)
{
    std::string fullpath = CCFileUtils::sharedFileUtils()->getWritablePath();
    fullpath += DB_NAME;
    return sqlite3_open(fullpath.c_str(), database);
}
/*
    テーブルを作成します
 */
void SQLiteScene::sqliteCreateTable()
{
    sqlite3 *db = NULL;
    if(sqliteOpen(&db) == SQLITE_OK){
        const char* sql_createtable = "CREATE TABLE testTable(key TEXT,value TEXT)";
        sqlite3_stmt* stmt = NULL;
        if(sqlite3_prepare_v2(db, sql_createtable, -1, &stmt, NULL) == SQLITE_OK){
            if(sqlite3_step(stmt) == SQLITE_DONE){
                CCLOG("create table done");
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
}
/*
    キーから値を取得します
 */
const char * SQLiteScene::sqliteGetValueForKey(const char *key)
{
    CCString* value = NULL;
    sqlite3* db = NULL;
    if(sqliteOpen(&db) == SQLITE_OK){
        const char *sql_select = "SELECT value FROM testTable WHERE key=?";
        sqlite3_stmt* stmt = NULL;
        if(sqlite3_prepare_v2(db,sql_select, -1, &stmt, NULL) == SQLITE_OK){
            sqlite3_bind_text(stmt, 1, key, -1, SQLITE_TRANSIENT);
            int ret = sqlite3_step(stmt);
            if(ret == SQLITE_DONE || ret == SQLITE_ROW){
                const char *val = (const char *)sqlite3_column_text(stmt, 0);
                value = CCString::create(val);
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    
    if(value != NULL){
        return value->getCString();
    }
    return NULL;
}
/*
    キーで値を設定します
 */
void SQLiteScene::sqliteSetValueForKey(const char *key,const char* value)
{
    sqlite3* db = NULL;
    if (sqliteOpen(&db) == SQLITE_OK) {
        
        const char *sql_select = "REPLACE INTO testTable(key,value) VALUES(?,?)";
        sqlite3_stmt *stmt = NULL;
        if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, NULL) == SQLITE_OK) {
            
            sqlite3_bind_text(stmt, 1, key, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, value, -1, SQLITE_TRANSIENT);
            if (sqlite3_step(stmt) == SQLITE_DONE) {
                
                CCLOG("replace key:%s value:%s",key,value);
                
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
}
/*
 すべての値をmapで返します
 */
void SQLiteScene::reloadSQLite()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLabelTTF* displayLabel = (CCLabelTTF*)this->getChildByTag(0);
    std::string resultText = "";
    
    sqlite3* db = NULL;
    if(sqliteOpen(&db) == SQLITE_OK){
        const char *sql_select = "SELECT key,value FROM testTable";
        sqlite3_stmt* stmt = NULL;
        if(sqlite3_prepare_v2(db,sql_select, -1, &stmt, NULL) == SQLITE_OK){
            // 一件ずつ取り出す
            while(sqlite3_step(stmt) == SQLITE_ROW){
                const char *key = (const char *)sqlite3_column_text(stmt, 0);
                const char *val = (const char *)sqlite3_column_text(stmt, 1);
                resultText+=key;
                resultText+=" : ";
                resultText+=val;
                resultText+="\n";
                
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    
    // ラベルにセット
    displayLabel->setString(resultText.c_str());
    displayLabel->setPosition(ccp(visibleSize.width*0.75, visibleSize.height/2));
}
/*
 editBoxの内容を取得し、SQLiteに登録します
 */
void SQLiteScene::regist()
{
    CCEditBox* editBoxKey = (CCEditBox*)this->getChildByTag(1);
    CCEditBox* editBoxVal = (CCEditBox*)this->getChildByTag(2);
    
    const char* key = editBoxKey->getText();
    const char* val = editBoxVal->getText();

    if(key != "" && val != ""){
        sqliteSetValueForKey(key, val);
        reloadSQLite();
    }
}