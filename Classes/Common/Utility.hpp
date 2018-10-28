//
//  Utility.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>

class Utility
{
public:
    static bool isTouchInsideTarget(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    static bool isTouchInsideNode(cocos2d::Touch* pTouch, cocos2d::Node* pNode);
    
    static cocos2d::SpriteFrame* getSpriteFrameByName(const std::string& resourceName);
};

#endif /* Utility_hpp */
