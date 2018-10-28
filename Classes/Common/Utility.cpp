//
//  Utility.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#include "Utility.hpp"

using namespace cocos2d;
using namespace std;

bool Utility::isTouchInsideTarget(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
    return Utility::isTouchInsideNode(pTouch, pEvent->getCurrentTarget());
}

bool Utility::isTouchInsideNode(cocos2d::Touch* pTouch, cocos2d::Node* pNode)
{
    return pNode->getBoundingBox().containsPoint(pNode->getParent()->convertTouchToNodeSpace(pTouch));
}

SpriteFrame* Utility::getSpriteFrameByName(const string& resourceName)
{
    SpriteFrame* pSpriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(resourceName.c_str());
    if (pSpriteFrame == nullptr)
    {
        Texture2D* pTexture = Director::getInstance()->getTextureCache()->addImage(resourceName.c_str());
        if (pTexture != nullptr)
        {
            pSpriteFrame = SpriteFrame::createWithTexture(pTexture, Rect(0, 0, pTexture->getPixelsWide(), pTexture->getPixelsHigh()));
        }
    }
    return pSpriteFrame;
}

