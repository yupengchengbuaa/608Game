//
//  MapScene.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#include "MapScene.hpp"
#include "ShaderSprite.hpp"

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
//    Node* pNode = Node::create();
//    addChild(pNode);
//
//    Sprite* pSprite1 = Sprite::create("HelloWorld.png");
//
//
//    pNode->addChild(pSprite1);
//    Size sz1 = pSprite1->getContentSize();
//
//    pSprite1->setScale(2);
//    Size sz2 = pSprite1->getContentSize();
//
//    pSprite1->setPosition(100, 100);
//    Size sz3 = pSprite1->getContentSize();
//
//    pSprite1->setFlippedX(true);
//    Size sz4 = pSprite1->getContentSize();
//
//    pSprite1->setTextureRect(Rect(50, 50, 100, 100));
//    Size sz5 = pSprite1->getContentSize();
    
    ShaderSprite* pSprite = new ShaderSprite();
    pSprite->initWithFile("HelloWorld.png");
    pSprite->setPosition(500, 500);
    addChild(pSprite);
    pSprite->initWithShader(ShaderSprite::VertexShader, ShaderSprite::FragmentShader, ShaderSprite::ShaderKey);
    
    
    return true;
}
