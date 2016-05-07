#ifndef CPPUTIL_CPP_UTIL_FILEUTIL_H
#define CPPUTIL_CPP_UTIL_FILEUTIL_H

#include <string>
#include <vector>

using namespace std;

namespace Util {

class FileUtil {
public:
    static bool Read(const string& filePath, string& content);
    static bool Read(const string& filePath, vector<string>& lineVec);
};

} //end namespace Util 
#endif //CPPUTIL_CPP_UTIL_FILEUTIL_H
