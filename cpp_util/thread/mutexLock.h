#ifndef CPP_UTIL_THREAD_MUTEXLOCK_H
#define CPP_UTIL_THREAD_MUTEXLOCK_H

#include <assert.h>
#include <pthread.h>
#include <tr1/memory>
#include "common/common.h"
#include "nonCopyable.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

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
typedef std::tr1::shared_ptr<MutexLock> MutexLockPtr;

class MutexLockGuard: private NonCopyable {
public:
    explicit MutexLockGuard(MutexLock& mutexLock);
    virtual ~MutexLockGuard();

private:
    MutexLock& mMutexLock; //must be a (& obj)
}; //class MutexLockGuard
typedef std::tr1::shared_ptr<MutexLockGuard> MutexLockGuardPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_MUTEXLOCK_H
