#ifndef CPPUTIL_CPP_UTIL_MUTEXLOCK_H
#define CPPUTIL_CPP_UTIL_MUTEXLOCK_H

#include <assert.h>
#include <pthread.h>
#include "non_copyable.h"
#include "logger.h"

using namespace std;
namespace Util {

class MutexLock: public NonCopyable {
public:
    MutexLock();
    virtual ~MutexLock();

private:
    void Lock();
    void UnLock();
    friend class MutexLockGuard;

public:
    pthread_mutex_t* GetPthreadMutex();

private:
    pthread_mutex_t mMutex;
};

class MutexLockGuard: private NonCopyable {
public:
    explicit MutexLockGuard(MutexLock& mutexLock);
    virtual ~MutexLockGuard();

private:
    MutexLock& mMutexLock; //must be a (& obj)
};

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_MUTEXLOCK_H
