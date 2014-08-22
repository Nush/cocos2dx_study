#ifndef __cocos2d_study__SuperClass__
#define __cocos2d_study__SuperClass__

#include "cocos2d.h"
class SuperClass
{
private:
    std::string m_name;
public:
    SuperClass():m_name("Super"){CCLOG("SuperClass コンストラクタ");};
    ~SuperClass();
    virtual void say();
    
    std::string getName(){return m_name;}
    void setName(std::string name){ this->m_name = name;}
    
    template <typename T_TYPE>
    T_TYPE add(T_TYPE a,T_TYPE b){ return a + b; }
};
#endif /* defined(__cocos2d_study__SuperClass__) */
