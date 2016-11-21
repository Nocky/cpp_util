#include "cpp_util/common/common.h"
#include "threadCondition.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

ThreadCondition::ThreadCondition(MutexLock& mutexLock)
    :mMutexLock(mutexLock) {
    assert(!pthread_cond_init(&mPcond, NULL));
}

ThreadCondition::~ThreadCondition() {
    assert(!pthread_cond_destroy(&mPcond));
}

void ThreadCondition::Wait() {
    assert(!pthread_cond_wait(&mPcond, mMutexLock.GetPthreadMutex()));
}

void ThreadCondition::Notify() {
    assert(!pthread_cond_signal(&mPcond));
}

void ThreadCondition::NotifyAll() {
    assert(!pthread_cond_broadcast(&mPcond));
}

NAMESPACE_END(Util)
