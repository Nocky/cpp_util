#include <assert.h>
#include "common/common.h"
#include "condition.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

Condition::Condition(MutexLock& mutexLock)
    :mMutexLock(mutexLock) {
    assert(!pthread_cond_init(&mCond, NULL));
}

Condition::~Condition() {
    assert(!pthread_cond_destroy(&mCond));
}

void Condition::Wait() {
    assert(mMutexLock.IsLock());
    assert(!pthread_cond_wait(&mCond, mMutexLock.GetMutex()));
}

void Condition::Notify() {
    assert(!pthread_cond_signal(&mCond));
}

NAMESPACE_END(Util)
