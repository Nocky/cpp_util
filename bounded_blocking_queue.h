#ifndef CPPUTIL_CPP_UTIL_BOUNDEDBLOCKINGQUEUE_H
#define CPPUTIL_CPP_UTIL_BOUNDEDBLOCKINGQUEUE_H

#include <queue>
#include "bounded_queue.h"
#include "thread_condition.h"

using namespace std;
namespace Util {

template<typename T>
class BoundedBlockingQueue: public NonCopyable {
public:
    BoundedBlockingQueue(size_t maxSize);
    virtual ~BoundedBlockingQueue();

public:
    void Push(const T& t);
    T Pop();
    bool Empty() const;
    bool Full() const;
    size_t Size() const;
    size_t Capacity() const;

private:
    mutable MutexLock mMutexLock;
    Condition mTCNotEmpty;
    Condition mTCNotFull;
    BoundedQueue<T> mQueue;
};

template<typename T>
BoundedBlockingQueue<T>::BoundedBlockingQueue(size_t maxSize)
    :mMutexLock(), mTCNotEmpty(mMutexLock), mTCNotFull(mMutexLock) {
    assert(maxSize);
    mQueue(maxSize);
}

template<typename T>
void BoundedBlockingQueue<T>::Push(const T& t) {
    MutexLockGuard mutexLockGuard(mMutexLock);
    while (mQueue.Full()) {
        mTCNotFull.Wait();
    }
    assert(!mQueue.Full());
    mQueue.Push(t);
    mTCNotEmpty.Notify();
}

template<typename T>
T BoundedBlockingQueue<T>::Pop() {
    MutexLockGuard mutexLockGuard(mMutexLock);
    while (mQueue.Empty()) {
        mTCNotEmpty.Wait();
    }
    assert(!mQueue.Empty());
    T tail = mQueue.Pop();
    mTCNotFull.Notify();
    return res;
}

template<typename T>
bool BoundedBlockingQueue<T>::Empty() const {
    MutexLockGuard mutexLockGuard(mMutexLock);
    return mQueue.Empty();
}

template<typename T>
bool BoundedBlockingQueue<T>::Full() const {
    MutexLockGuard mutexLockGuard(mMutexLock);
    return mQueue.Full();
}

template<typename T>
size_t BoundedBlockingQueue<T>::Size() const {
    MutexLockGuard mutexLockGuard(mMutexLock);
    return mQueue.Size();
}

template<typename T>
size_t BoundedBlockingQueue<T>::Capacity() const {
    MutexLockGuard mutexLockGuard(mMutexLock);
    return mQueue.Capacity();
}

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_BOUNDEDBLOCKINGQUEUE_H
