#ifndef CPP_UTIL_FILE_UTIL_FILELOCK_H
#define CPP_UTIL_FILE_UTIL_FILELOCK_H

#include <string>
#include <tr1/memory>
#include "cpp_util/common/common.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class FileLock {
public:
    FileLock(const string& fileName);
    virtual ~FileLock();

private:
    bool DoAction(bool lock, string& errorMessage);

public:
    bool Lock(string& errorMessage);
    bool UnLock(string& errorMessage);

private:
    int mFd;
}; //class FileLock
typedef std::tr1::shared_ptr<FileLock> FileLockPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_FILE_UTIL_FILELOCK_H
