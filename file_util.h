#ifndef CPPUTIL_CPP_UTIL_FILEUTIL_H
#define CPPUTIL_CPP_UTIL_FILEUTIL_H

#include <string>

using namespace std;

namespace Util {

class FileUtil {
public:
    static bool Read(const string& filePath, string& content);
};

} //end namespace Util 
#endif //CPPUTIL_CPP_UTIL_FILEUTIL_H
