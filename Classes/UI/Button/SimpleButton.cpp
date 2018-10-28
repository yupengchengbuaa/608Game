//
//  SimpleButton.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#include "SimpleButton.hpp"
#include "Utility.hpp"

using namespace std;
using namespace cocos2d;

SimpleButton::SimpleButton()
{
    m_pLabel = nullptr;
    m_pSprite = nullptr;
}

SimpleButton* SimpleButton::create(ButtonType type, const string& text)
{
    SimpleButton* pButton = new (nothrow) SimpleButton;
    if (pButton != nullptr && pButton->init(type, text))
    {
        pButton->autorelease();
        return pButton;
    }
    CC_SAFE_DELETE(pButton);
    return nullptr;
}

SimpleButton* SimpleButton::creatWithRes(const string& normalPngRes, const string& selectedPngRes)
{
    SimpleButton* pButton = new (nothrow) SimpleButton;
    if (pButton != nullptr && pButton->init(normalPngRes, selectedPngRes))
    {
        pButton->autorelease();
        return pButton;
    }
    CC_SAFE_DELETE(pButton);
    return nullptr;
}

bool SimpleButton::init(ButtonType type, const string& text)
{
    BaseButton::init();
    
    string fontName = "fonts/Marker Felt.ttf";
    
    m_pSprite = Sprite::create("CloseNormal.png");
    
    m_pContainer->addChild(m_pSprite);
    
    setContentSize(m_pSprite->getContentSize());
    
    m_pLabel = Label::createWithTTF(text, fontName, 24);
    
    m_pContainer->addChild(m_pLabel);
    
    return true;
}

bool SimpleButton::init(const string& normalPngRes, const string& selectedPngRes)
{
    BaseButton::init();
    
    m_strNormalPngRes = normalPngRes;
    m_strselectedPngRes = selectedPngRes;
    
    m_pSprite = Sprite::create(normalPngRes);
    
    m_pContainer->addChild(m_pSprite);
    
    setContentSize(m_pSprite->getContentSize());
    
    //检查selectedPngRes有效性
    
    
    return true;
}

void SimpleButton::setNormalState()
{
    if (m_state != STATE::NORMAL)
    {
        m_state = STATE::NORMAL;
        if (m_strNormalPngRes != "" && m_strNormalPngRes != "")
        {
            m_pSprite->setSpriteFrame(Utility::getSpriteFrameByName(m_strNormalPngRes));
        }
        else
        {
            m_pContainer->stopAllActions();
            float dt = (1.f - m_pContainer->getScale()) / 20.f;
            m_pContainer->runAction(EaseElasticOut::create(ScaleTo::create(dt, 1.f)));
        }
    }
}

void SimpleButton::setSelectedState()
{
    if (m_state != STATE::SELECTED)
    {
        m_state = STATE::SELECTED;
        if (m_strNormalPngRes != "" && m_strselectedPngRes != "")
        {
            m_pSprite->setSpriteFrame(Utility::getSpriteFrameByName(m_strselectedPngRes));
        }
        else
        {
            m_pContainer->stopAllActions();
            float dt = (m_pContainer->getScale() - 0.8f) / 20.f;
            m_pContainer->runAction(EaseElasticOut::create(ScaleTo::create(dt, 0.8f)));
        }
    }
}
