#ifndef CPP_UTIL_COMMON_FILEUTIL_H
#define CPP_UTIL_COMMON_FILEUTIL_H

#include <string>
#include <vector>

using namespace std;
namespace Util {

class FileUtil {
public:
    static bool Read(const string& filePath, string& content);
    static bool Read(const string& filePath, vector<string>& lineVec);
    static bool Write(const string& filePath, const string& content, bool append = false);
}; //class FileUtil

} //namespace Util 
#endif //CPP_UTIL_COMMON_FILEUTIL_H
