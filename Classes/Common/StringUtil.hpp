//
//  StringUtil.hpp
//  A608
//
//  Created by yupengcheng on 2018/10/30.
//

#ifndef StringUtil_hpp
#define StringUtil_hpp

#include <functional>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <functional>

template<typename T>
std::string num2str(T n)
{
    std::stringstream ss;
    ss << n;
    return ss.str();
}

template<typename T>
T str2num(const std::string& s)
{
    T num = (T)0;
    std::stringstream ss(s);
    ss >> num;
    return num;
}

void stringSplit(std::string src, const char* token, std::vector<std::string>& vect);

template<typename T>
std::vector<T> stringSplitToNum(std::string src, const char* token)
{
    std::vector<std::string> rgStr;
    stringSplit(src, token, rgStr);
    std::vector<T> result;
    for (int i = 0; i < rgStr.size(); i++)
    {
        result.push_back(str2num<T>(rgStr.at(i)));
    }
    return result;
}

std::string stringReplace(const std::string& src, const std::string& strToReplace, const std::string& strReplaceTo);

bool isDigitOrAlpha(const std::string& content);

std::string decimalTo62Radix(unsigned long long decimalNum);

std::unordered_map<std::string, std::string> parseHttpUrlParameter(const std::string& url);

//// 从utf8str中依次找出符合条件的ANSI字符
//std::string getAnsiStrFormUTF8Str(const std::string& str, std::function<bool(const char&)>predicate);

// 将string中的byte index 转换成char index，中文当做一个index
size_t convertByteIndexToCharIndex(std::string& str, size_t byteIndex);

std::string trim(const std::string& str);

#endif /* StringUtil_hpp */
