#include <assert.h>
#include "include/util/code_converter.h"

using namespace std; 

namespace Util {

CodeConverter::CodeConverter(const char* fromCharset, const char* toCharset) { 
	assert(fromCharset != NULL);
	assert(toCharset != NULL);
	mIconvHandle = iconv_open(toCharset, fromCharset); 
} 

CodeConverter::~CodeConverter() { 
	iconv_close(mIconvHandle); 
}

bool CodeConverter::Convert(const string& srcStr, string& desStr) {
	char* srcPtr = (char*)srcStr.c_str();
	size_t srcSize = srcStr.size();

	desStr.resize(srcSize*2);
	char* desPtr = (char*)desStr.c_str();
	size_t desSize = desStr.size();

	if(size_t(-1) == iconv(mIconvHandle, &srcPtr, &srcSize, &desPtr, &desSize)) {
		desStr.clear();
        return false;
	}
    desStr.resize(strlen(desStr.c_str()));
	return true;
}

} // end namespace Util
