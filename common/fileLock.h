#ifndef CPP_UTIL_COMMON_FILELOCK_H
#define CPP_UTIL_COMMON_FILELOCK_H

#include <string>
#include <tr1/memory>

using namespace std;
namespace Util {

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
typedef std::tr1::shared_ptr<FileLock*> FileLockPtr;

} //namespace Util 
#endif //CPP_UTIL_COMMON_FILELOCK_H
