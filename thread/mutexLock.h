#ifndef CPP_UTIL_THREAD_MUTEXLOCK_H
#define CPP_UTIL_THREAD_MUTEXLOCK_H

#include <assert.h>
#include <pthread.h>
#include "nonCopyable.h"
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
}; //class MutexLock

class MutexLockGuard: private NonCopyable {
public:
    explicit MutexLockGuard(MutexLock& mutexLock);
    virtual ~MutexLockGuard();

private:
    MutexLock& mMutexLock; //must be a (& obj)
}; //class MutexLockGuard

} //namespace Util
#endif //CPP_UTIL_THREAD_MUTEXLOCK_H
