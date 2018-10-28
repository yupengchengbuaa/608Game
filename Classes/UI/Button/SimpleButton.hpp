//
//  SimpleButton.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/28.
//

#ifndef SimpleButton_hpp
#define SimpleButton_hpp

#include <stdio.h>
#include "BaseButton.hpp"

enum class ButtonType{
    NORMAL
};

class SimpleButton : public BaseButton
{
    CC_SYNTHESIZE_READONLY(cocos2d::Sprite*, m_pSprite, Sprite);
    CC_SYNTHESIZE_READONLY(cocos2d::Label*, m_pLabel, Label);
    //TODO 按钮添加音效
    //CC_SYNTHESIZE(std::string, m_strEffects, EffectRes);
public:
    SimpleButton();
    static SimpleButton* create(ButtonType type, const std::string& text);
    static SimpleButton* creatWithRes(const std::string& normalPngRes, const std::string& selectedPngRes);
protected:
    bool init(ButtonType type, const std::string& text);
    bool init(const std::string& normalPngRes, const std::string& selectedPngRes);
    virtual void setNormalState() override;
    virtual void setSelectedState() override;
    
private:
    std::string m_strNormalPngRes = "";
    std::string m_strselectedPngRes = "";
};

#endif /* SimpleButton_hpp */
