#ifndef CPP_UTIL_THREAD_POOL_THREADPOOL_H
#define CPP_UTIL_THREAD_POOL_THREADPOOL_H

#include "common/common.h"
#include "nonCopyable.h"
#include "task.h"
#include "baseThread.h"
#include "workerThread.h"
#include "bufferQueue.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class ThreadPool: public NonCopyable {
public:
    ThreadPool(size_t threadNum, size_t taskQueueSize);
    virtual ~ThreadPool();

public:
    void Start();
    void AddTask(TaskPtr& task);

private:
    size_t mWorkerThreadNum;
    size_t mTaskBufferQueueSize;
    BufferQueuePtr mTaskBufferQueue;
    vector<BaseThreadPtr> mWorkerThreadVec;
}; //class ThreadPool
typedef std::tr1::shared_ptr<ThreadPool> ThreadPoolPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_THREADPOOL_H
