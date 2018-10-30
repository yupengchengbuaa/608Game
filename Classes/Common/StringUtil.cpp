//
//  StringUtil.cpp
//  A608
//
//  Created by yupengcheng on 2018/10/30.
//

#include "StringUtil.hpp"
#include <sstream>
#include <algorithm>
#include "cocos2d.h"
extern "C"
{
#include "utf.h"
}

using namespace std;
using namespace cocos2d;

void stringSplit(string src, const char* token, vector<string>& vect)
{
    if (src.empty())
    {
        return;
    }
    int nend = 0;
    int nbegin = 0;
    while (nend != -1)
    {
        nend = (int)src.find(token, nbegin);
        if (nend == -1)
        {
            vect.push_back(src.substr(nbegin, src.length()-nbegin));
        }
        else
        {
            vect.push_back(src.substr(nbegin, nend-nbegin));
        }
        nbegin = nend + (int)strlen(token);
    }
}

std::string stringReplace(const std::string& src, const std::string& strToReplace, const std::string& strReplaceTo)
{
    string newStr = src;
    string::size_type pos = 0;
    string::size_type toReplaceSize = strToReplace.size();
    string::size_type replaceToSize = strReplaceTo.size();
    while((pos = newStr.find(strToReplace, pos)) != string::npos)
    {
        newStr.replace(pos, toReplaceSize, strReplaceTo);
        pos += replaceToSize;
    }
    return newStr;
}

bool isDigitOrAlpha(const std::string& content)
{
    for (const char& item : content)
    {
        if ( (item >= 'a' && item <= 'z') ||
            (item >= 'A' && item <= 'Z') ||
            (item >= '0' && item <= '9'))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

static const string CHAR_SET = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string decimalTo62Radix(unsigned long long decimalNum)
{
    if (decimalNum == 0)
    {
        return "0";
    }
    
    string resultStr = "";
    unsigned long long originNum = decimalNum;
    const int RadixNum = 62;
    unsigned int remainder = 0;
    vector<unsigned int> result;
    while (originNum != 0) //数制转换，结果存入数组s[m]
    {
        remainder = originNum % RadixNum;
        originNum = originNum / RadixNum;
        result.push_back(remainder); //将余数按顺序存入数组s[m]中
    }
    
    for (auto it = result.rbegin(); it != result.rend(); it++) //输出转换后的序列
    {
        resultStr += CHAR_SET.at(*it);
    }
    
    return resultStr;
}

unordered_map<string, string> parseHttpUrlParameter(const string& url)
{
    unordered_map<string, string> mapMsg;
    
    auto iter = std::find(url.begin(), url.end(), '?');
    if (iter == url.end())
    {
        return mapMsg;
    }
    string strMsg;
    std::copy(++iter, url.end(), std::back_inserter(strMsg));
    
    vector<string> parts;
    stringSplit(strMsg, "&", parts);
    
    for (const string& item : parts)
    {
        vector<string> subParts;
        stringSplit(item, "=", subParts);
        
        if (subParts.size() != 2)
        {
            continue;
        }
        
        mapMsg.insert({subParts[0], subParts[1]});
    }
    
    return mapMsg;
}

//string getAnsiStrFormUTF8Str(const string& str, function<bool(const char&)>predicate)
//{
//    if (str.empty() == true)
//        return "";
//    
//    cocos2d::StringUtils::StringUTF8 utf8Str(str);
//    
//    int i = 0;
//    while (i != utf8Str.length())
//    {
//        auto& c = utf8Str.getString()[i];
//        if (c.isASCII() &&
//            (predicate == nullptr || (predicate != nullptr && predicate(c._char[0]) == true)))
//        {
//            ++i;
//        }
//        else
//        {
//            utf8Str.deleteChar(i);
//        }
//    }
//    
//    return utf8Str.getAsCharSequence();
//}

size_t convertByteIndexToCharIndex(std::string& str, size_t byteIndex)
{
    if (!utf8_check_string(str.c_str(), static_cast<int>(str.size())))
    {
        CCLOG("%s: %d %s input string is not utf8 encoded.", __FILE__, __LINE__, __FUNCTION__);
        return byteIndex;
    }
    
    int charIdx= 0;
    for (int i = 0; i < str.size(); i++)
    {
        int byteCnt = utf8_check_first(str[i]);
        if (i <= byteIndex && (i + byteCnt) > byteIndex)
        {
            return charIdx;
        }
        if (byteCnt != 0)
        {
            charIdx++;
            i += byteCnt - 1;
        }
    }
    return charIdx;
}

std::string trim(const std::string& str)
{
    string result = str;
    
    result.erase(0, result.find_first_not_of(" \n\r\t"));
    result.erase(result.find_last_not_of(" \n\r\t") + 1);
    
    return result;
}
