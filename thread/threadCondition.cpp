#include "thread/threadCondition.h"

using namespace std;
namespace Util {

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

} //namespace Util
