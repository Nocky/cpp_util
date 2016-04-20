#ifndef SIMHASH_SERVER_INCLUDE_UTIL_CODECONVERTER_H
#define SIMHASH_SERVER_INCLUDE_UTIL_CODECONVERTER_H

#include <iconv.h> 
#include <memory.h>
#include <iostream> 

using namespace std; 

namespace Util {

class CodeConverter { 
public:
	CodeConverter(const char *fromCharset, const char *toCharset);
	virtual ~CodeConverter();	

public:
	bool Convert(const string& srcStr, string& desStr);

private: 
	iconv_t mIconvHandle; 
}; 

} //end namespace Util
#endif //SIMHASH_SERVER_INCLUDE_UTIL_CODECONVERTER_H
