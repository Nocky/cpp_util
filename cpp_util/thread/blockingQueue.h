#ifndef CPP_UTIL_THREAD_BLOCKINGQUEUE_H
#define CPP_UTIL_THREAD_BLOCKINGQUEUE_H

#include <queue>
#include "cpp_util/common/common.h"
#include "mutexLock.h"
#include "boundedQueue.h"
#include "threadCondition.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

template<typename T>
class BlockingQueue: public NonCopyable {
public:
    BlockingQueue();
    virtual ~BlockingQueue();

public:
    void Push(const T& t);
    T Pop();
    size_t Size() const;
    bool Empty() const;

private:
    mutable MutexLock mMutexLock;
    ThreadCondition mThreadCondition;
    std::queue<T> mQueue;
}; //class BlockingQueue

template<typename T>
BlockingQueue<T>::BlockingQueue()
    :mMutexLock(), mThreadCondition(mMutexLock){
}

template<typename T>
BlockingQueue<T>::~BlockingQueue() {
}
                
template<typename T>
void BlockingQueue<T>::Push(const T& t) {
    // mutex lock
    MutexLockGuard mutexLockGuard(mMutexLock);
    mQueue.push(t);
    // send signal to thread 
    mThreadCondition.Notify();
}

template<typename T>
T BlockingQueue<T>::Pop() {
    MutexLockGuard mutexLockGuard(mMutexLock);
    // always use a while-loop, due to spurious wakeup
    while (mQueue.empty()) {
        mThreadCondition.Wait();
    }
    assert(!mQueue.empty());
    T front = mQueue.front();
    mQueue.pop();
    return front;
}

template<typename T>
size_t BlockingQueue<T>::Size() const {
    MutexLockGuard mutexLockGuard(mMutexLock);
    return mQueue.size();
}

template<typename T>
bool BlockingQueue<T>::Empty() const {
    MutexLockGuard mutexLockGuard(mMutexLock);
    return Size() == 0;
}

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_BLOCKINGQUEUE_H
