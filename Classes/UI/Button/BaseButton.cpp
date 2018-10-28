//
//  BaseButton.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#include "BaseButton.hpp"
#include "Utility.hpp"

using namespace cocos2d;

bool BaseButton::init()
{
    setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    setCascadeColorEnabled(true);
    setCascadeOpacityEnabled(true);
    
    m_pContainer = Node::create();
    m_pContainer->setCascadeColorEnabled(true);
    m_pContainer->setCascadeOpacityEnabled(true);
    addChild(m_pContainer);
    
    m_pTouchListener = EventListenerTouchOneByOne::create();
    m_pTouchListener->setSwallowTouches(true);
    m_pTouchListener->onTouchBegan = CC_CALLBACK_2(BaseButton::onTouchBegan, this);
    m_pTouchListener->onTouchMoved = CC_CALLBACK_2(BaseButton::onTouchMoved, this);
    m_pTouchListener->onTouchEnded = CC_CALLBACK_2(BaseButton::onTouchEnded, this);
    m_pTouchListener->onTouchCancelled = CC_CALLBACK_2(BaseButton::onTouchCancelled, this);
    
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_pTouchListener, this);
    
    m_state = STATE::NORMAL;
    
    return true;
}

bool BaseButton::onTouchBegan(Touch* pTouch, Event* pEvent)
{
    //如果按钮无法显示在屏幕上，则无法接受Touch事件
    Node* pNode = this;
    while (pNode != nullptr)
    {
        if (pNode->isVisible())
        {
            pNode = pNode->getParent();
        }
        else
        {
            return false;
        }
        
    }
    
    if (Utility::isTouchInsideTarget(pTouch, pEvent))
    {
        setSelectedState();
        return true;
    }
    return false;
}

void  BaseButton::onTouchMoved(Touch* pTouch, Event* pEvent)
{
    if (!Utility::isTouchInsideTarget(pTouch, pEvent) && m_state == STATE::SELECTED)
    {
        setNormalState();
    }
}

void BaseButton::onTouchEnded(Touch* pTouch, Event* pEvent)
{
    if (m_state == STATE::SELECTED)
    {
        setNormalState();
        if (Utility::isTouchInsideTarget(pTouch, pEvent))
        {
            setNormalState();
            if (m_touchCallback != nullptr)
            {
                m_touchCallback();
            }
        }
    }
}

void BaseButton::onTouchCancelled(Touch* pTouch, Event* pEvent)
{
    if (m_state == STATE::SELECTED)
    {
        setNormalState();
    }
}

void BaseButton::setNormalState()
{
    if (m_state != STATE::NORMAL)
    {
        m_state = STATE::NORMAL;
        m_pContainer->stopAllActions();
        float dt = (1.f - m_pContainer->getScale()) / 20.f;
        m_pContainer->runAction(EaseElasticOut::create(ScaleTo::create(dt, 1.f)));
    }
}

void BaseButton::setSelectedState()
{
    if (m_state !=  STATE::SELECTED)
    {
        m_state = STATE::SELECTED;
        m_pContainer->stopAllActions();
        float dt = (m_pContainer->getScale() - 0.8f) / 20.f;
        m_pContainer->runAction(EaseElasticOut::create(ScaleTo::create(dt, 0.8f)));
    }
}

void BaseButton::disable()
{
    setColor(Color3B(150, 150, 150));
    toggleTouchListener(false);
}

void BaseButton::toggleTouchListener(bool enable)
{
    m_pTouchListener->setEnabled(enable);
}
