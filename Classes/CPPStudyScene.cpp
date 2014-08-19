#include "CPPStudyScene.h"
#include "STLStudy.h"

CCScene* CPPStudyScene::scene()
{
    CCScene* scene = CCScene::create();
    CPPStudyScene* layer = CPPStudyScene::create();
    scene->addChild(layer);
    return scene;
}

bool CPPStudyScene::init()
{
    STLStudy* stl = new STLStudy("name");
    stl->studyVector();
    stl->studySet();
    stl->studyMap();
    stl->studyList();
    
    return true;
}