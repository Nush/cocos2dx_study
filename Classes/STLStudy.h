#ifndef __cocos2d_study__STLScene__
#define __cocos2d_study__STLScene__

#include "cocos2d.h"
USING_NS_CC;
class STLStudy{
private:
    const char* m_name;
    std::vector<int> m_vectorData;
    std::set<int> m_setData;
    std::map<const char*, int, std::greater<std::string> > m_mapData;
    std::list<const char*> m_listData;
public:
    STLStudy();
    STLStudy(const char* name);
    ~STLStudy();
    
    // setter,getter
    const char* getName();
    void setName(const char* name);
    
    // STL練習(意味ないことします)
    void studyVector();
    void studySet();
    void studyMap();
    void studyList();
};
#endif /* defined(__cocos2d_study__STLScene__) */
