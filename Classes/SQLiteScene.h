#ifndef __cocos2d_study__SQLiteScene__
#define __cocos2d_study__SQLiteScene__
#include "cocos2d.h"
#include "SQlite/sqlite3.h"
USING_NS_CC;
using namespace cocos2d;
class SQLiteScene : public CCLayer
{
private:
    int sqliteOpen(sqlite3 **database);
    void sqliteCreateTable();
    const char * sqliteGetValueForKey(const char * key);
    void sqliteSetValueForKey(const char* key,const char* value);
    
    void regist();
    void reloadSQLite();
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(SQLiteScene);
};
#endif /* defined(__cocos2d_study__SQLiteScene__) */
