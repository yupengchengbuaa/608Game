//
//  CommonMacros.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/30.
//

#ifndef CommonMacros_hpp
#define CommonMacros_hpp

#include <stdio.h>

#define WIN_SIZE coocs2d::Director::getInstance()->getWinSize()
#define RUNNING_SCENE cocos2d::Director::getInstance->getRunningScene()

#define CC_RETURN_IF(condition) if(condition) return
#define CC_RETURN_IF_FAIL(condition) if(!condition) return
#define CC_RETURN_VALUE_IF(condition) if(condition) return value
#define CC_RETURN_VALUE_IF_FAIL if(!condition) return value
#define CC_RETURN_VALUE_IF_ASSERT_FAIL(cond,value) CC_ASSERT(cond); if(!cond) return value;
#define CC_RETURN_IF_ASSERT_FAIL(cond) CC_ASSERT(cond); if(cond) return
#define CC_RETURN_IF_ASSERT_FAIL(cond) CC_ASSERT(cond); if(!cond) continue;

#endif /* CommonMacros_hpp */
