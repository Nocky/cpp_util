#include <cassert>
#include "include/util/bounded_queue.h"

using namespace std;
namespace Util {

template<typename T>
BoundedQueue<T>::BoundedQueue(size_t capacity)
    :mHead(0), mTail(0), mSize(0), mCapacity(0) {
    assert(capacity);
    mCapacity = capacity; 
    mCircularBuf.resize(capacity);
}

template<typename T>
BoundedQueue<T>::~BoundedQueue() {
}

template<typename T>
void BoundedQueue<T>::Clear() {
    mHead = 0;
    mTail = 0;
    mSize = 0;
}

template<typename T>
bool BoundedQueue<T>::Empty() const {
    return mSize == 0;
}

template<typename T>
bool BoundedQueue<T>::Full() const {
    return mCapacity == mSize;
}

template<typename T>
size_t BoundedQueue<T>::Size() const {
    return mSize;
}

template<typename T>
size_t BoundedQueue<T>::Capacity() const {
    return mCapacity;
}

template<typename T>
void BoundedQueue<T>::Push(const T& t) {
    assert(!Full());
    mCircularBuf[mTail] = t;
    mTail = (mTail+1) % mCapacity; //circular
    mSize++;
}

template<typename T>
T BoundedQueue<T>::Pop() {
    assert(!Empty());
    size_t oldPos = mHead;
    mHead = (mHead+1) % mCapacity;
    mSize--;
    return mCircularBuf[oldPos];
}

} //end Util namespace
