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

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_BOUNDEDBLOCKINGQUEUE_H
