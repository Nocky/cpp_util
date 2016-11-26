#include <iostream>
#include <string>
#include <algorithm>
#include "common/stdExtension.h"
#include "common/common.h"
#include "stringUtil.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

bool StringUtil::StringFormat(string& res, const char* fmt, ...) {
	// default size 256 bytes
    size_t size = 256;
    va_list ap;
    while (true) {
        res.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)res.c_str(), size, fmt, ap);
        va_end(ap);
		// success write to res and buffer < size
        if (n > -1 && n < size) {
            res.resize(n);
            return true;
        }
		// fail write
		else if (n > -1) {
            size = n + 1;
		}
		// buffer >= size
        else {
            size *= 2;
		}
    }
	return false;
}

string StringUtil::StringFormat(const char* fmt, ...) {
	// default size 256 bytes
    size_t size = 256;
    va_list ap;
	string res = "";
    while (true) {
        res.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)res.c_str(), size, fmt, ap);
        va_end(ap);
		// success write to res and buffer < size
        if (n > -1 && n < size) {
            res.resize(n);
            return res;
        }
		// fail write
		else if (n > -1) {
            size = n + 1;
		}
		// buffer >= size
        else {
            size *= 2;
		}
    }
	return res;
}

bool StringUtil::Split(const string& str, vector<string>& vec, const string& sep, bool saveEmpty) {
	if (str == ""){
		return false;
	}
	vec.clear();
	size_t start = 0;
	size_t strSize = str.size();
	while (start < strSize) {
		size_t pos = str.find_first_of(sep, start);
		if (pos == string::npos){
			if (saveEmpty || pos-start > 0) {
				vec.push_back(str.substr(start));
			}
			return true;
		}
		if (saveEmpty || pos-start > 0) {
			vec.push_back(str.substr(start, pos-start));
		}
		start = pos+sep.size();
	}
	return true;
}

size_t StringUtil::Split(const string& str, const string& sep, bool saveEmpty) {
	if (str == ""){
		return 0;
	}
	size_t start = 0;
	size_t strSize = str.size();
	size_t cnt = 0;
	while (start < strSize) {
		size_t pos = str.find_first_of(sep, start);
		if (pos == string::npos){
			if (saveEmpty || pos-start > 0) {
				cnt++;
			}
			break;
		}
		if (saveEmpty || pos-start > 0) {
			cnt++;
		}
		start = pos+sep.size();
	}
	return cnt;
}

void StringUtil::Upper(string& str) {
    size_t strSize = str.size();
    for (size_t i = 0; i < strSize; ++i) {
        str[i] = toupper(str[i]); 
    }
}

void StringUtil::Lower(string& str) {
    size_t strSize = str.size();
    for (size_t i = 0; i < strSize; ++i) {
        str[i] = tolower(str[i]); 
    }
}

string StringUtil::Ltrim(string& str, const char x) {
    size_t start = 0;
    size_t len = str.length();
    while (start < len && str[start] == x) {
        ++start;
    }
    return str.substr(start);
}

string StringUtil::Rtrim(string& str, const char x) {
    // var end type must be int not size_t
    // because when str is empty length()-1 set to size_t will be return mas number
    int end = str.length() - 1;
    while (end > (-1) && str[end] == x) {
        --end;
    }
    return str.substr(0, end+1);
}

string StringUtil::Trim(string& str, const char x) {
    str = Rtrim(str, x);
    return Ltrim(str, x);
}

string StringUtil::Trim(char* ptr, const char x) {
    string str = string(ptr);
    str = Rtrim(str, x);
    return Ltrim(str, x);
}

bool StringUtil::StartsWith(const string& str, const string& prefix) {
    size_t strSize = str.length();
    size_t prefixSize = prefix.length();
    if (strSize < prefixSize) {
        return false;
    }
    return str.compare(0, prefixSize, prefix) == 0;
}

bool StringUtil::StartsWith(const char* ptr, const string& prefix) {
    string str = string(ptr);
    return StartsWith(str, prefix);
}

bool StringUtil::EndsWith(const string& str, const string& suffix) {
    size_t strSize = str.length();
    size_t suffixSize = suffix.length();
    if (strSize < suffixSize) {
        return false;
    }
    return str.compare((strSize-suffixSize), suffixSize, suffix) == 0;
}

bool StringUtil::IsInStr(const string& str, char x) {
    return str.find(x) != string::npos;
}

uint16_t StringUtil::TwoCharToUint16(char high, char low) {
    return (((uint16_t)high & 0x00ff) << 8) | ((uint16_t)low & 0x00ff);
}

string StringUtil::GetCurrentTime(const string format) {
    time_t timeNow;
    time(&timeNow);
    size_t maxSize = 64;
    // string must be has enough storage space
    string timeStr = "";
    timeStr.resize(64);
    size_t len = strftime(const_cast<char*>(timeStr.c_str()), (size_t)maxSize, format.c_str(), localtime(&timeNow));
    timeStr.resize(len);
    return timeStr; 
}

/*
  |  Unicode符号范围      |  UTF-8编码方式  
n |  (十六进制)           | (二进制)  
---+-----------------------+------------------------------------------------------  
1 | 0000 0000 ~ 0000 007F |                            0xxxxxxx  
2 | 0000 0080 ~ 0000 07FF |                   110xxxxx 10xxxxxx  
3 | 0000 0800 ~ 0000 FFFF |          1110xxxx 10xxxxxx 10xxxxxx  
4 | 0001 0000 ~ 0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  
 * */
bool StringUtil::Utf8ToUnicode(const char* const ptr, const size_t len, UnicodeContainer& vec) {
    if (NULL == ptr) {
        return false;
    }
    vec.clear();
    for(size_t i = 0; i < len; i++) {
        // ptr[i] must be uint8_t type
        // utf8 -> 0xxxxxxx
        if((uint8_t)ptr[i] <= 0x7f) {
            // ptr[i] -> 0xxx xxx, total 7 bit
            uint32_t uVal = (uint8_t)(ptr[i]) & 0x7f;
            vec.push_back(uVal);
        } 
        // utf-8 -> 110xxxxx 10xxxxxx
        else if ((uint8_t)ptr[i] <= 0xdf && (i+1 < len)) {
            // ptr[i] -> 110x xxxx, total 5 bit
            uint32_t u1 = ((uint8_t)(ptr[i]) & 0x1f) << 6;
            // ptr[i+1] -> 10xx xxxx, total 6 bit
            uint32_t u2 = (uint8_t)(ptr[++i]) & 0x3f;
            // unicode bit
            uint32_t uVal = u1 | u2; 
            vec.push_back(uVal);
        }
        // utf-8 -> 1110xxxx 10xxxxxx 10xxxxxx
        else if((uint8_t)ptr[i] <= 0xef && (i+2 < len)) {
            // ptr[i] -> 1110xxxx, total 4 bit
            uint32_t u1 = ((uint8_t)(ptr[i]) & 0x0f) << 12;
            // ptr[i+1] -> 10xxxxx, total 6 bit
            uint32_t u2 = ((uint8_t)(ptr[++i]) & 0x3f) << 6;
            // ptr[i+2] -> 10xxxxx, total 6 bit
            uint32_t u3 = ((uint8_t)(ptr[++i]) & 0x3f);
            uint32_t uVal = u1 | u2 | u3;
            vec.push_back(uVal);
        } 
        // utf-8 -> 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        else if((uint8_t)ptr[i] <= 0xf7 && (i+3 < len)) {
            // ptr[i] -> 11110xxx, total 3 bit
            uint32_t u1 = ((uint8_t)(ptr[i]) & 0x07) << 18;
            // ptr[i+1] -> 10xxxxxx, total 6 bit
            uint32_t u2 = ((uint8_t)(ptr[++i]) & 0x3f) << 12;
            // ptr[i+2] -> 10xxxxxx, total 6 bit
            uint32_t u3 = ((uint8_t)(ptr[++i]) & 0x3f) << 6;
            // ptr[i+3] -> 10xxxxxx, total 6 bit
            uint32_t u4 = ((uint8_t)(ptr[++i]) & 0x3f);
            uint32_t uVal = (u1 | u2) | (u3 | u4);
            vec.push_back(uVal);
        }
        else {
            return false;
        }
    }
    return true;
}

bool StringUtil::Utf8ToUnicode(const string& str, UnicodeContainer& vec) {
    return Utf8ToUnicode(str.c_str(), str.size(), vec);
}

/*
  |  Unicode符号范围      |  UTF-8编码方式  
n |  (十六进制)           | (二进制)  
---+-----------------------+------------------------------------------------------  
1 | 0000 0000 ~ 0000 007F |                            0xxxxxxx  
2 | 0000 0080 ~ 0000 07FF |                   110xxxxx 10xxxxxx  
3 | 0000 0800 ~ 0000 FFFF |          1110xxxx 10xxxxxx 10xxxxxx  
4 | 0001 0000 ~ 0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  
*/
bool StringUtil::UnicodeToUtf8(UnicodeContainerIter begin, UnicodeContainerIter end, string& res) {
    if (begin > end) {
        return false;
    }
    res = "";
    while (begin != end) {
        uint32_t uVal = *begin;
        if (uVal <= 0x7f) {
            res += char(uVal);
        }
        else if (uVal <= 0x7ff) {
            res += char(((uVal>>6) & 0x1f) | 0xc0);
            res += char(((uVal) & 0x3f) | 0x80);
        }
        else if (uVal <= 0xffff) {
            res += char(((uVal>>12) & 0x0f) | 0xe0);
            res += char(((uVal>>6) & 0x3f) | 0x80);
            res += char(((uVal) & 0x3f) | 0x80);
        }
        else if (uVal <= 0x10ffff){
            res += char(((uVal>>18) & 0x07) | 0xf0);
            res += char(((uVal>>12) & 0x3f) | 0x80);
            res += char(((uVal>>6) & 0x3f) | 0x80);
            res += char(((uVal) & 0x3f) | 0x80);
        }
        else {
            return false;
        }
        ++begin;
    }
    return true;
}

bool StringUtil::GBKToUnicode(const char* const ptr, const size_t len, UnicodeContainer& vec) {
    vec.clear();
    if (NULL == ptr) {
        return false;
    }
    for (size_t i = 0; i < len; i++) {
        // english letters ptr[i] <= 127
        if ((uint8_t)ptr[i] <= 0x7f) {
            uint32_t uVal = (uint8_t)ptr[i];
            vec.push_back(uVal);
        }
        // chinese letters
        else if (i+1 < len) {
            uint32_t u1 = ((uint8_t(ptr[i]) & 0xff) << 8);
            uint32_t u2 = (uint8_t(ptr[++i]) & 0xff);
            uint32_t uVal = u1 | u2;
            vec.push_back(uVal);
        }
        else {
            return false;
        }
    }
    return true;
}

bool StringUtil::GBKToUnicode(const string& str, UnicodeContainer& vec) {
    return GBKToUnicode(str.c_str(), str.size(), vec);
}

bool StringUtil::UnicodeToGBK(UnicodeContainerIter begin, UnicodeContainerIter end, string& res) {
    if (begin > end) {
        return false;
    }
    res = "";
    while (begin != end) {
        uint32_t uVal = *begin;
        char c1 = char((uVal >> 8) & 0xff); 
        char c2 = char(uVal & 0xff); 
        // if c1 > 127
        if ((uint32_t)c1 & 0x80) {
            res += c1;
        }
        res += c2;
        ++begin;
    }
    return true;
}

string StringUtil::Quote(const string& rawStr) {
    string quoteStr = "";
#if 0
    size_t rawStrSz = rawStr.size();
    for (size_t i = 0; i < rawStrSz; i++) {
        char c = rawStr[i];
        char buff[4];
        memset(buff, '\0', 4);
        if (isalnum(c) || unquoteChars.find(string(c)) != unquoteChars.end()) {
            buff[0] = c; 
        }
        else {
            buff[0] = '%';
        }
        quoteStr += string(buff);
    }
#endif
    return quoteStr;
}

string StringUtil::UnQuote(const string& quoteStr) {
    string rawStr = "";
    return rawStr;
}

NAMESPACE_END(Util)
