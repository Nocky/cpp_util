#include "cpp_util/common/common.h"
#include "mutexLock.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

MutexLock::MutexLock() {
    assert(!pthread_mutex_init(&mMutex, NULL));
}

MutexLock::~MutexLock() {
    assert(!pthread_mutex_destroy(&mMutex));
}

void MutexLock::Lock() {
    assert(!pthread_mutex_lock(&mMutex));
}

void MutexLock::UnLock() {
    assert(!pthread_mutex_unlock(&mMutex));
}

pthread_mutex_t* MutexLock::GetPthreadMutex() {
    return &mMutex;
}

MutexLockGuard::MutexLockGuard(MutexLock& mutexLock) 
    :mMutexLock(mutexLock) {
    mMutexLock.Lock();
}

MutexLockGuard::~MutexLockGuard() {
    mMutexLock.UnLock();
}

NAMESPACE_END(Util)
