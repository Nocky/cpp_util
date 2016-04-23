#ifndef CPPUTIL_CPP_UTIL_BLOCKINGQUEUE_H
#define CPPUTIL_CPP_UTIL_BLOCKINGQUEUE_H

#include <queue>
#include "bounded_queue.h"
#include "thread_condition.h"

using namespace std;
namespace Util {

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
};

template<typename T>
BlockingQueue<T>::BlockingQueue()
    :mMutexLock(), mThreadCondition(mMutexLock){
}

template<typename T>
BlockingQueue<T>::~BlockingQueue() {
}
                
template<typename T>
void BlockingQueue::Push(const T& t) {
    // mutex lock
    MutexLockGuard mutexLockGuard(mMutexLock);
    mQueue.push(x);
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
    return size() == 0;
}

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_BLOCKINGQUEUE_H
