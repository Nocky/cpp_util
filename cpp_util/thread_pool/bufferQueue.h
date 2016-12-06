#ifndef CPP_UTIL_THREAD_POOL_BUFFERQUEUE_H
#define CPP_UTIL_THREAD_POOL_BUFFERQUEUE_H

#include <queue>
#include "common/common.h"
#include "task.h"
#include "mutexLock.h"
#include "condition.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class BufferQueue: public NonCopyable {
public:
    BufferQueue(size_t maxSize);
    virtual ~BufferQueue();

public:
    void Push(TaskPtr& task);
    TaskPtr& Pop();

private:
    size_t mSize;
    mutable MutexLock mMutexLock;
    Condition mEmptyCondition;
    Condition mFullCondition;
    queue<TaskPtr> mQueue;
}; //class BufferQueue 
typedef std::tr1::shared_ptr<BufferQueue> BufferQueuePtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_BUFFERQUEUE_H
