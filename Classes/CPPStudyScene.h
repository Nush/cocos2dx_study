#ifndef __cocos2d_study__CPPStudyScene__
#define __cocos2d_study__CPPStudyScene__

#include "cocos2d.h"
#include "SuperClass.h"
USING_NS_CC;
class CPPStudyScene : public CCLayer
{
private:
    void poinsterTest(SuperClass* pSuper);
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(CPPStudyScene);
    
    // 列挙型
    enum e_Status{
        READY = 0,
        PLAY = 1,
        PAUSE = 2,
        END = 3
    };
    // 構造体
    struct s_Player{
        const char* name;
        int hp;
        int mp;
        int at;
        int df;
        s_Player(){
            this->hp = 1;
            this->mp = 1;
            this->at = 1;
            this->df = 1;
        }
        s_Player(int h,int m,int a,int d){
            this->hp = h;
            this->mp = m;
            this->at = a;
            this->df = d;
        }
    };
};

#endif /* defined(__cocos2d_study__CPPStudyScene__) */
