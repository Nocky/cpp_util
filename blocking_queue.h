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

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_BLOCKINGQUEUE_H
