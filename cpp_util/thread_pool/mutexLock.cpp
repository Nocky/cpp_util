#include <assert.h>
#include "common/common.h"
#include "mutexLock.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

MutexLock::MutexLock() 
    :mStatus(false){
    assert(!pthread_mutex_init(&mMutex, NULL));
}

MutexLock::~MutexLock() {
    assert(!mStatus);
    assert(!pthread_mutex_destroy(&mMutex));
}

void MutexLock::Lock() {
    assert(!pthread_mutex_lock(&mMutex));
    mStatus = true;
}

void MutexLock::UnLock() {
    assert(!pthread_mutex_unlock(&mMutex));
    mStatus = false;
}

pthread_mutex_t* MutexLock::GetMutex() {
    return &mMutex;
}

bool MutexLock::IsLock() {
    return mStatus;
}

NAMESPACE_END(Util)
