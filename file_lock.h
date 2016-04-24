#ifndef CPPUTIL_CPP_UTIL_FILELOCK_H
#define CPPUTIL_CPP_UTIL_FILELOCK_H

#include <string>

using namespace std;

namespace Util {

class FileLock {
public:
    FileLock(const string& fileName);
    virtual ~FileLock();

private:
    bool LUnock(bool lock, string& errorMessage);

public:
    bool Lock(string& errorMessage);
    bool UnLock(string& errorMessage);

private:
    int mFd;
};

} //end namespace Util 
#endif //CPPUTIL_CPP_UTIL_FILELOCK_H
