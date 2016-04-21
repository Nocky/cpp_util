#include "std_extention.h"
#include "string_util.h"
#include "code_converter.h"

using namespace std;

namespace Util { 

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
			if (saveEmpty || pos-start > 1) {
				vec.push_back(str.substr(start));
			}
			return true;
		}
		if (saveEmpty || pos-start > 1) {
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
			if (saveEmpty || pos-start > 1) {
				cnt++;
			}
			break;
		}
		if (saveEmpty || pos-start > 1) {
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

bool StringUtil::StartsWith(const string& str, const string& prefix) {
    size_t strSize = str.length();
    size_t prefixSize = prefix.length();
    if (strSize < prefixSize) {
        return false;
    }
    return str.compare(0, prefixSize, prefix) == 0;
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

string StringUtil::GetCurrentTime(const string& format) {
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

bool StringUtil::CodeCharsetConverter(const char* fromCharset, const char* toCharset, const string& srcStr, string& desStr) {
    if (NULL == fromCharset || NULL == toCharset) {
        return false;
    }
    CodeConverter codeConverter(fromCharset, toCharset); 
    return codeConverter.Convert(srcStr, desStr);
}

} //end namespace Util
