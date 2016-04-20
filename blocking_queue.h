#ifndef SIMHASH_SERVER_INCLUDE_UTIL_BLOCKINGQUEUE_H
#define SIMHASH_SERVER_INCLUDE_UTIL_BLOCKINGQUEUE_H

#include <queue>
#include "include/util/bounded_queue.h"
#include "include/util/thread_condition.h"

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

} //end Util namespace
#endif //SIMHASH_SERVER_INCLUDE_UTIL_BLOCKINGQUEUE_H
