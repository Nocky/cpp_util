#ifndef CPP_UTIL_THREAD_POOL_MUTEXLOCK_H
#define CPP_UTIL_THREAD_POOL_MUTEXLOCK_H

#include <assert.h>
#include <pthread.h>
#include "common/common.h"
#include "nonCopyable.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class MutexLock: public NonCopyable {
public:
    MutexLock();
    virtual ~MutexLock();

private:
    MutexLock(const MutexLock&);
    MutexLock& operator=(const MutexLock&);

public:
    void Lock();
    void UnLock();
    pthread_mutex_t* GetMutex();
    bool IsLock();

private:
    bool mStatus;
    pthread_mutex_t mMutex;
}; //class MutexLock
typedef std::tr1::shared_ptr<MutexLock> MutexLockPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_MUTEXLOCK_H
