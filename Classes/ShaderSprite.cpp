//
//  ShaderSprite.cpp
//  A608
//
//  Created by yupengcheng on 2018/11/12.
//

#include "ShaderSprite.hpp"

using namespace cocos2d;

const char* ShaderSprite::ShaderKey = "shader_key";

const char* ShaderSprite::VertexShader = " \
attribute vec4 a_position;\
attribute vec4 a_color;\
attribute vec2 a_texcoord;\
varying vec2 v_texcoord;\
varying vec4 v_fragmentColor;\
void main(){\
gl_Position = CC_PMatrix * a_position;\
v_fragmentColor = a_color;\
v_texcoord = a_texcoord;\
}\
";

const char* ShaderSprite::FragmentShader = " \
#ifdef GL_ES \n\
precision highp float; \n\
#endif \n\
varying vec2 v_texcoord; \
uniform float u_time; \
void main(){ \
vec4 incolor = texture2D(CC_Texture0, v_texcoord); \
float factor = (sin(u_time)+1.0)/3.0;\
vec4 outcolor = vec4(0.8, 0.8, 0.8, 0.8)*factor + incolor*(1.0-factor); \
gl_FragColor = vec4(outcolor.xyz, incolor.w); \
} \
";

void ShaderSprite::initWithShader(const char* vertexShader, const char* fragmentShader, const char* key)
{
    GLProgram* pProgram = GLProgramCache::getInstance()->getGLProgram(key);
    if (pProgram == nullptr)
    {
        pProgram = GLProgram::createWithByteArrays(vertexShader, fragmentShader);
        GLProgramCache::getInstance()->addGLProgram(pProgram, key);
    }
    
    m_pProgramState = GLProgramState::create(pProgram);
    
    scheduleUpdate();
}

void ShaderSprite::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    m_pProgramState->setUniformFloat("u_time", u_time);
    setGLProgramState(m_pProgramState);
    
    Sprite::draw(renderer, transform, flags);
}

void ShaderSprite::update(float dt)
{
    u_time += dt;
}
