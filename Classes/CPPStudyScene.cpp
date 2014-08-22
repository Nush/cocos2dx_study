#include "CPPStudyScene.h"
#include "STLStudy.h"
#include "SuperClass.h"
#include "SubClass.h"

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
    
    CCLOG("=============キャスト=============");
    CCLOG("----------アップキャスト-----------");
    // dynamic_cast
    CCLOG("- dynamic_cast非使用");
    SuperClass* super1 = new SubClass();
    super1->say();
    //superSub->move();
    CCLOG("super1: %d",super1);
    
    CCLOG("- dynamic_cast使用");
    SubClass* sub1 = new SubClass();
    sub1->say();
    SuperClass* superSub1 = dynamic_cast<SuperClass*>(sub1);
    superSub1->say();
    
    CCLOG("sub1: %d",sub1);
    CCLOG("superSub: %d\n",superSub1);
    
    CCLOG("----------ダウンキャスト-----------");
    SuperClass* super2 = new SuperClass();
    super2->say();
    
    SubClass* sub2 = dynamic_cast<SubClass*>(super2);
    CCLOG("純粋なSuperClassをダウンキャストしようとしても、ダメ！");
    CCLOG("super2: %d",super2);
    CCLOG("sub2: %d\n",sub2);
    
    CCLOG("アップキャストしたSubClass:superSub2");
    SuperClass* superSub2 = new SubClass();
    superSub2->say();
    
    CCLOG("それをダウンキャスト");
    SubClass* sub3 = dynamic_cast<SubClass*>(superSub2);
    sub3->say();
    sub3->move();
    
    CCLOG("superSub2: %d",superSub2);
    CCLOG("sub3: %d\n",sub3);
    
    CCLOG("=============列挙体=============");
    CCLOG("enum e_Status");
    e_Status status = READY;
    CCLOG("status = READY");
    CCLOG("%d\n",status);
    
    status = PLAY;
    CCLOG("status = PLAY");
    CCLOG("%d\n",status);
    
    status = PAUSE;
    CCLOG("status = PAUSE");
    CCLOG("%d\n",status);
    
    
    status = END;
    CCLOG("status = END");
    CCLOG("%d\n",status);
    
    
    CCLOG("=============構造体=============");
    CCLOG("struct s_Player");
    struct s_Player shun(100,80,110,90);
    CCLOG("HP: %d",shun.hp);
    CCLOG("MP: %d",shun.mp);
    CCLOG("AT: %d",shun.at);
    CCLOG("DF: %d\n",shun.df);
    
    
    CCLOG("=============ポインタのテスト============");
    SuperClass* pSuper = new SuperClass();
    this->poinsterTest(pSuper);
    CCLOG("%s \n",pSuper->getName().c_str());
    
    
    CCLOG("=============テンプレートのテスト============");
    int a = pSuper->add(5, 5);
    CCLOG("%d",a);
    
    return true;
}
void CPPStudyScene::poinsterTest(SuperClass *pSuper)
{
    pSuper->setName("Ultra");
}