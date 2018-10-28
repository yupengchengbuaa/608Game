//
//  MapScene.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#ifndef MapScene_hpp
#define MapScene_hpp

#include <stdio.h>

class MapLayer : public cocos2d::Layer
{
    CREATE_FUNC(MapLayer);
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
};

#endif /* MapScene_hpp */
