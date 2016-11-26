#ifndef CPP_UTIL_FILE_UTIL_FILEUTIL_H
#define CPP_UTIL_FILE_UTIL_FILEUTIL_H

#include <string>
#include <vector>
#include "common/common.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class FileUtil {
public:
    static bool Read(const string& filePath, string& content);
    static bool Read(const string& filePath, vector<string>& lineVec);
    static bool Write(const string& filePath, const string& content, bool append = false);
}; //class FileUtil

NAMESPACE_END(Util)
#endif //CPP_UTIL_FILE_UTIL_FILEUTIL_H
