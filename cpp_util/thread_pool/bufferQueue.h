#ifndef CPP_UTIL_THREAD_POOL_BUFFERQUEUE_H
#define CPP_UTIL_THREAD_POOL_BUFFERQUEUE_H

#include <queue>
#include "common/common.h"
#include "mutexLock.h"
#include "condition.h"
#include "task.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class BufferQueue: public NonCopyable {
public:
    BufferQueue(size_t maxSize);
    virtual ~BufferQueue();

private:
    BufferQueue(const BufferQueue&);
    BufferQueue& operator=(const BufferQueue&);

public:
    void Push(Task* task);
    Task* Pop();

private:
    size_t mSize;
    mutable MutexLock mMutexLock;
    Condition mEmptyCondition;
    Condition mFullCondition;
    queue<Task*> mQueue;
}; //class BufferQueue 
typedef std::tr1::shared_ptr<BufferQueue> BufferQueuePtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_BUFFERQUEUE_H
