#include "STLStudy.h"
#include <algorithm>
// 簡単にイテレータを扱うためのマクロ
#define foreach(stlType,stl,it) for(stlType::iterator it=(stl).begin();(it)!=(stl).end();(it)++)

/*
 コンストラクタ、デストラクタ
 */
STLStudy::STLStudy()
{
    m_name = "No name";
    CCLOG("コンストラクタ：引数なし");
}
STLStudy::STLStudy(const char* name)
{
    m_name = name;
    CCLOG("コンストラクタ：引数あり");
}
STLStudy::~STLStudy()
{
    CCLOG("デストラクタ");
}
const char* STLStudy::getName()
{
    return m_name;
}
void STLStudy::setName(const char* name)
{
    m_name = name;
}

/*
 STLの練習
 */
void STLStudy::studyVector()
{
    CCLOG("std:vector");
    std::vector<int>::iterator it;
    
    m_vectorData.push_back(1);
    m_vectorData.push_back(2);
    m_vectorData.push_back(3);
    m_vectorData.push_back(5);
    m_vectorData.push_back(6);
    
    CCLOG("普通の配列のように扱う");
    for(int i = 0;i < m_vectorData.size();i++){
        CCLOG("%d",m_vectorData[i]);
    }
    
    
    CCLOG("要素の削除");
    m_vectorData.erase(m_vectorData.begin()+4);
    foreach(std::vector<int>, m_vectorData, i){
        CCLOG("%d",*i);
    }
    
    CCLOG("要素の挿入");
    it = m_vectorData.begin()+3;
    m_vectorData.insert(it,4);
    foreach(std::vector<int>, m_vectorData, i){
        CCLOG("%d",*i);
    }
    
    
    
}
void STLStudy::studySet()
{
    std::set<int>::iterator it;
    
    CCLOG("std:set");
    CCLOG("最初の順番");
    CCLOG("%d",2);
    CCLOG("%d",5);
    CCLOG("%d",4);
    CCLOG("%d",1);
    CCLOG("%d",3);
    
    m_setData.insert(2);
    m_setData.insert(5);
    m_setData.insert(4);
    m_setData.insert(1);
    m_setData.insert(3);
    
    
    CCLOG("イテレートすると");
    foreach(std::set<int>, m_setData, i){
        CCLOG("%d",*i);
    }
}
void STLStudy::studyMap()
{
    std::map<const char*, int,std::greater<std::string> >::iterator it;
    CCLOG("std:map");
    
    m_mapData.insert(std::pair<const char*, int>("田中",22));
    m_mapData.insert(std::pair<const char*,int>("佐藤",25));
    m_mapData.insert(std::pair<const char*,int>("高橋",20));
    
}
void STLStudy::studyList()
{
}

