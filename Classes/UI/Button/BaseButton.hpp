//
//  BaseButton.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#ifndef BaseButton_hpp
#define BaseButton_hpp

#include <stdio.h>

class BaseButton : public cocos2d::Node
{
public:
    void setTouchCallback(std::function<void()> callback);
    void toggleTouchListener(bool enable);
    
    virtual void setNormalState();
    virtual void setSelectedState();
    
    void disable();
protected:
    bool init() override;
    bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
    void onTouchCancelled(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
protected:
    enum class STATE{INVALID, NORMAL, SELECTED};
    STATE m_state = STATE::INVALID;
    std::function<void()> m_touchCallback = nullptr;
    cocos2d::EventListenerTouchOneByOne* m_pTouchListener = nullptr;
    cocos2d::Node* m_pContainer = nullptr;
};

#endif /* BaseButton_hpp */
