//
//  MapScene.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#include "MapScene.hpp"

using namespace cocos2d;

Scene* MapLayer::createScene()
{
    auto scene = Scene::create();
    
    auto layer = MapLayer::create();
    
    scene->addChild(layer);
    return scene;
}

bool MapLayer::init()
{
    Sprite* pBackGround = Sprite::create("HelloWorld.png");
    addChild(pBackGround);
    return true;
}
