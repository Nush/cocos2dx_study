#include "BuilderScene.h"

//CocosBuilderとの連携のために読み込む
#include "CCBReader.h"
#include "CCNodeLoaderLibrary.h"

#include "CCBLayerLoader.h"
USING_NS_CC;
USING_NS_CC_EXT;
CCScene* BuilderScene::scene()
{
    CCScene* scene = CCScene::create();
    BuilderScene* layer = BuilderScene::create();
    scene->addChild(layer,0);
    return scene;
}
bool BuilderScene::init()
{
    CCNodeLoaderLibrary* lib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    lib->registerCCNodeLoader("CCBLayer", CCBLayerLoader::loader());
    CCBReader* reader = new CCBReader(lib);
    CCNode* node = reader->readNodeGraphFromFile("BackgroundLayer.ccbi");
    reader->autorelease();
    this->addChild(node);
    return true;
}
