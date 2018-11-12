//
//  ShaderSprite.hpp
//  A608
//
//  Created by yupengcheng on 2018/11/12.
//

#ifndef ShaderSprite_hpp
#define ShaderSprite_hpp

#include "CCSprite.h"

class ShaderSprite : public cocos2d::Sprite
{
public:
    void initWithShader(const char* vertexShader, const char* fragmentShader, const char* key);
private:
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
    void update(float dt) override;
private:
    cocos2d::GLProgramState* m_pProgramState;
    float u_time;
    
public:
    static const char* ShaderKey;
    static const char* VertexShader;
    static const char* FragmentShader;
};

#endif /* ShaderSprite_hpp */
