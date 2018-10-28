//
//  Utility.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#include "Utility.hpp"

bool Utility::isTouchInsideTarget(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
    return Utility::isTouchInsideNode(pTouch, pEvent->getCurrentTarget());
}

bool Utility::isTouchInsideNode(cocos2d::Touch* pTouch, cocos2d::Node* pNode)
{
    return pNode->getBoundingBox().containsPoint(pNode->getParent()->convertTouchToNodeSpace(pTouch));
}

