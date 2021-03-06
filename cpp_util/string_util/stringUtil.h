/*
 * 1. Implementing template member functions is somewhat different compared to the regular class member functions. The declarations and definitions of the class template member functions should all be in the same header file. The declarations and definitions need to be in the same header file
**/

#ifndef CPP_UTIL_STRING_UTIL_STRINGUTIL_H
#define CPP_UTIL_STRING_UTIL_STRINGUTIL_H

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "common/common.h"
#include "common/stdExtension.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

typedef vector<uint32_t> UnicodeContainer;
typedef vector<uint32_t>::const_iterator UnicodeContainerIter;

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
    static string Trim(char* ptr, const char x = ' ');

    /*
     * 1. judge str is startswith prefix
     * 2. return true/false
     * */
    static bool StartsWith(const string& str, const string& prefix);
    static bool StartsWith(const char* ptr, const string& prefix);

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
    static string GetCurrentTime(const string format = "%Y-%m-%d %H:%M:%S");

    /*
     * 1. utf8 transform to unicode 32 bit
     * 2. return true/false
     * */
    static bool Utf8ToUnicode(const char* const ptr, const size_t len, UnicodeContainer& vec);
    static bool Utf8ToUnicode(const string& str, UnicodeContainer& vec);

    /*
     * 1. unicode transform to utf-8
     * 2. return true/false
     * */
    static bool UnicodeToUtf8(UnicodeContainerIter begin, UnicodeContainerIter end, string& res);

    /*
     * 1. GBK transform to Unicode
     * 2. return true/false
     * */
    static bool GBKToUnicode(const char* const ptr, const size_t len, UnicodeContainer& vec);
    static bool GBKToUnicode(const string& str, UnicodeContainer& vec);

    /*
     * 1. GBK transform to Unicode
     * 2. return true/false
     * */
    static bool UnicodeToGBK(UnicodeContainerIter begin, UnicodeContainerIter end, string& res);
    
    /*
     * 1. unsigned int value to Hex char
     *    0~15 -> '0'~'F'
     * 2. return char
     * */
    static char ToHex(unsigned int value);

    /*
     * 1. from hex to unsigned int
     *    '0'~'F' -> 0~15
     * 2. return unsigned int
     * */
    static unsigned int FromHex(char hex);

    /*
     * 1. quote string
     * 2. return quote string
     * */
    static string Quote(const string& rawStr);
    
    /*
     * 1. unquote string
     * 2. return raw string
     * */
    static string UnQuote(const string& quoteStr);

private:
    static const string QUOTE_SAVE_CHARS;

}; //class StringUtil

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

NAMESPACE_END(Util)
#endif //CPP_UTIL_STRING_UTIL_STRINGUTIL_H
