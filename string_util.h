/*
 * 1. Implementing template member functions is somewhat different compared to the regular class member functions. The declarations and definitions of the class template member functions should all be in the same header file. The declarations and definitions need to be in the same header file
**/

#ifndef CPPUTIL_CPP_UTIL_STRINGUTIL_H
#define CPPUTIL_CPP_UTIL_STRINGUTIL_H

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "std_extension.h"

using namespace std;

namespace Util {

class StringUtil {
private:
    StringUtil();
    virtual ~StringUtil();

private:
    StringUtil(StringUtil&);
    StringUtil& operator=(StringUtil&);

public:
	/*
	 * 1. output format data to string 
	 * 2. example: "name:%s, age:%d" -> "name:chenguolin, age:18"
	 * 3. return true/false
	 * */
    static bool StringFormat(string& str, const char* fmt, ...);

	/*
	 * 1. output format data to string 
	 * 2. example: "name:%s, age:%d" -> "name:chenguolin, age:18"
	 * 3. return format string
	 * */
    static string StringFormat(const char* fmt, ...);

	/*
	 * 1. join T begin~end all element
	 * 2. example: vector [1,2,3,4] 
	 *             join 1~3, connector +
	 *             return 1+2+3
	 * 3. return true/false
	 * */
    template<typename T>
    static bool Join(T begin, T end, string& str, const string& connector);

	/*
	 * 1. join T begin~end all element
	 * 2. example: vector [1,2,3,4] 
	 *             join 1~3, connector +
	 *             return 1+2+3
	 * 3. return connect string
	 * */
    template<typename T>
    static string Join(T begin, T end, const string& connector);

	/*
	 * 1. split string with sep 
	 * 2. example: a&b&c, with '&' split -> [a],[b],[c]
	 * 3. default not save empty substr, 
	 *	  3.1 false: a&&b->[a],[b]
	 *	  3.2 true: a&&b ->[a],[],[b]
	 * 4. return true/false
	 * */
    static bool Split(const string& str, vector<string>& vec, const string& sep, bool saveEmpty = false);

	/*
	 * 1. split string with sep 
	 * 2. example: a&b&c, with '&' split -> [a],[b],[c]
	 * 3. default not save empty substr, 
	 *	  3.1 false: a&&b->[a],[b]
	 *	  3.2 true: a&&b ->[a],[],[b]
	 * 4. return split size
	 * */
    static size_t Split(const string& str, const string& sep, bool saveEmpty = false);

	/*
	 * 1. transform all char to UPPER
	 * 2. return true/false
	 * */
    static void Upper(string& str);

	/*
	 * 1. transform all char to LOWER 
	 * 2. return true/false
	 * */
    static void Lower(string& str);

    /*
     * 1. string remove all left char x
     * 2. default char x is space
     * 3. return string
     * */
    static string Ltrim(string& str, const char x = ' '); 

    /*
     * 1. string remove all right char x
     * 2. default char x is space
     * 3. return string
     * */
    static string Rtrim(string &str, const char x = ' ');
    
	/*
	 * 1. trim string, remove left and right char x
	 * 2. return string 
	 * */
    static string Trim(string &str, const char x = ' ');

    /*
     * 1. judge str is startswith prefix
     * 2. return true/false
     * */
    static bool StartsWith(const string& str, const string& prefix);

    /*
     * 1. judge str is endswith prefix
     * 2. return true/false
     * */
    static bool EndsWith(const string& str, const string& suffix);

    /*
     * 1. judge char x is in str
     * 2. return true/false 
     */
    static bool IsInStr(const string& str, char x);

    /*
     * 1. combine two char and trans to unit16
     * 2. return uint16_t
     * */
    static uint16_t TwoCharToUint16(char high, char low);

    /*
     * 1. get current time
     * 2. return format string
     * */
    static string GetCurrentTime(const string& format = "%Y-%m-%d %H:%M:%S");

    /*
     * 1. code charset converter
     * 2. return true/false 
     * */    
    static bool CodeCharsetConverter(const char* fromCharset, const char* toCharSet, const string& srcStr, string& desStr);

    /*
     * 1. utf8 to unicode
     * 2. return true/false
     * */
    template<typename Uint16Container>
    static bool Utf8ToUnicode(const char* const ptr, size_t len, Uint16Container& vec);

    template<typename Uint16Container>
    static bool Utf8ToUnicode(const string& str, Uint16Container& vec);

}; //end class StringUtil

template<typename T>
bool StringUtil::Join(T begin, T end, string& str, const string& connector) {
	if (begin == end) {
		return true;
	}
	stringstream ss;
	ss << *begin;
	begin++;
	while (begin != end) {
		ss << connector << *begin; // call std_extension operator << funtion
		begin++;
	}
	str = ss.str();
	return true;
}

template<typename T>
string StringUtil::Join(T begin, T end, const string& connector) {
	string res = "";
	if (begin == end) {
		return res;
	}
	stringstream ss;
	ss << *begin;
	begin++;
	while (begin != end) {
		ss << connector << *begin; // call std_extension operator << funtion
		begin++;
	}
	return ss.str();
}

/*
  |  Unicode符号范围      |  UTF-8编码方式  
n |  (十六进制)           | (二进制)  
---+-----------------------+------------------------------------------------------  
1 | 0000 0000 ~ 0000 007F |                                              0xxxxxxx  
2 | 0000 0080 ~ 0000 07FF |                                     110xxxxx 10xxxxxx  
3 | 0000 0800 ~ 0000 FFFF |                            1110xxxx 10xxxxxx 10xxxxxx  
4 | 0001 0000 ~ 0010 FFFF |                   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  
5 | 0020 0000 ~ 03FF FFFF |          111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
6 | 0400 0000 ~ 7FFF FFFF | 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
 * */
template <typename Uint16Container>
static bool StringUtil::Utf8ToUnicode(const char* const ptr, size_t len, Uint16Container& vec) {
    if (NULL == ptr) {
        return false;
    }
    vec.clear();
    for(size_t i = 0; i < len;) {
        // 0xxxxxxx
        if(!(ptr[i] & 0x80)) {
            vec.push_back(ptr[i]);
            i++;
        } 
        // 
        else if((uint8_t)ptr[i] <= 0xdf && (i+1 < len)) {
            char c1 = (ptr[i] >> 2) & 0x07;
            char c2 = (ptr[i+1] & 0x3f) | ((ptr[i] & 0x03) << 6);
            uint16_t tmp = (((uint16_t(c1)&0x00ff) << 8) | (uint16_t(c2) & 0x00ff));
            vec.push_back(tmp);
            i += 2;
        } 
        else if((uint8_t)ptr[i] <= 0xef && (i+2) < len) {
            char c1 = ((uint8_t)ptr[i] << 4) | ((ptr[i+1] >> 2) & 0x0f );
            char c2 = (((uint8_t)ptr[i+1] << 6) & 0xc0) | (ptr[i+2] & 0x3f);
            uint16_t tmp = (((uint16_t(c1) & 0x00ff) << 8) | (uint16_t(c2) & 0x00ff));
            vec.push_back(tmp);
            i += 3;
        } 
        else {
            return false;
        }
    }
    return true;
}

template<typename Uint16Container>
bool StringUtil::Utf8ToUnicode(const string& str, Uint16Container& vec) {
    return Utf8ToUnicode(str.c_str(), str.size(), vec);
}

} //end namespace Util
#endif //CPPUTIL_CPP_UTIL_STRINGUTIL_H
