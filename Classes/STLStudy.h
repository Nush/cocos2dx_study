#ifndef __cocos2d_study__STLScene__
#define __cocos2d_study__STLScene__

#include "cocos2d.h"
USING_NS_CC;
class STLStudy{
private:
    char* m_name;
    std::vector<int> m_vectorData;
    std::set<int> m_setData;
    std::map<char*, int, std::greater<std::string> > m_mapData;
    std::list<char*> m_listData;
public:
    STLStudy();
    STLStudy(char* name);
    ~STLStudy();
    
    // setter,getter
    char* getName();
    void setName(char* name);
    
    // STL練習(意味ないことします)
    void studyVector();
    void studySet();
    void studyMap();
    void studyList();
};
#endif /* defined(__cocos2d_study__STLScene__) */
