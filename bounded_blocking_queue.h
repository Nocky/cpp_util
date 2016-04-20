#ifndef SIMHASH_SERVER_INCLUDE_UTIL_BOUNDEDBLOCKINGQUEUE_H
#define SIMHASH_SERVER_INCLUDE_UTIL_BOUNDEDBLOCKINGQUEUE_H

#include <queue>
#include "include/util/bounded_queue.h"
#include "include/util/thread_condition.h"

using namespace std;
namespace Util {

template<typename T>
class BoundedBlockingQueue: public NonCopyable {
public:
    explicit BoundedBlockingQueue(size_t maxSize);
    virtual ~BoundedBlockingQueue();

public:
    void Push(const T& t);
    T pop();
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
#endif //SIMHASH_SERVER_INCLUDE_UTIL_BOUNDEDBLOCKINGQUEUE_H
