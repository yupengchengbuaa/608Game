//
//  SingletonTemplate.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/30.
//

#ifndef SingletonTemplate_hpp
#define SingletonTemplate_hpp

template<typename T>
class SingletonTemplate
{
public:
    static T* getInstance()
    {
        static T* pInstance = nullptr;
        if (pInstance == nullptr)
        {
            pInstance = new T();
        }
        
        return pInstance;
    }
    
protected:
    SingletonTemplate(){};
    virtual ~SingletonTemplate(){};
    SingletonTemplate(const SingletonTemplate<T>&); //拷贝构造函数不实现
    SingletonTemplate<T>& operator=(const SingletonTemplate<T>&); //赋值函数不实现
};

template<typename T>
class SingletonTemplateInit
{
public:
    static T* getInstance()
    {
        static T* pInstance = nullptr;
        if (pInstance == nullptr)
        {
            pInstance = new T();
            pInstance->init();
        }
        
        return pInstance;
    }
    
protected:
    SingletonTemplateInit(){};
    virtual ~SingletonTemplateInit(){};
    SingletonTemplateInit(const SingletonTemplateInit<T>&); //拷贝构造函数不实现
    SingletonTemplateInit<T>& operator=(const SingletonTemplateInit<T>&); //赋值函数不实现
};

#endif /* SingletonTemplate_hpp */
