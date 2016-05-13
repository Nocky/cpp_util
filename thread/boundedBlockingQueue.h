#ifndef CPP_UTIL_THREAD_BOUNDEDBLOCKINGQUEUE_H
#define CPP_UTIL_THREAD_BOUNDEDBLOCKINGQUEUE_H

#include <queue>
#include "thread/boundedQueue.h"
#include "thread/threadCondition.h"

using namespace std;
namespace Util {

template<typename T>
class BoundedBlockingQueue: public NonCopyable {
public:
    explicit BoundedBlockingQueue(size_t maxSize);
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
    ThreadCondition mTCNotEmpty;
    ThreadCondition mTCNotFull;
    BoundedQueue<T> mQueue;
}; //class BoundedBlockingQueue

template<typename T>
BoundedBlockingQueue<T>::BoundedBlockingQueue(size_t maxSize)
    :mMutexLock(), 
    mTCNotEmpty(mMutexLock), 
    mTCNotFull(mMutexLock), 
    mQueue(maxSize) {
    assert(maxSize);
}

template<typename T>
BoundedBlockingQueue<T>::~BoundedBlockingQueue() {
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
    return tail;
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

} //namespace Util
#endif //CPP_UTIL_THREAD_BOUNDEDBLOCKINGQUEUE_H
