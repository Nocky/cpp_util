#ifndef CPPUTIL_CPP_UTIL_CONDITION_H
#define CPPUTIL_CPP_UTIL_CONDITION_H

#include "thread_condition.h"

using namespace std;
namespace Util {

ThreadCondition::ThreadCondition(MutexLock& mutexLock)
    :mMutex(mutexLock) {
    assert(!pthread_cond_init(&mPcond, NULL));
}

virtual ThreadCondition::~ThreadCondition() {
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

} //end namespace Util