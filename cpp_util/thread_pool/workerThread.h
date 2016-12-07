#ifndef CPP_UTIL_THREAD_POOL_WORKERTHREAD_H
#define CPP_UTIL_THREAD_POOL_WORKERTHREAD_H

#include "common/common.h"
#include "bufferQueue.h"
#include "baseThread.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class WorkerThread: public BaseThread {
public:
    WorkerThread(BufferQueuePtr& taskQueue);
    virtual ~WorkerThread();

private:
    WorkerThread(const WorkerThread&);
    WorkerThread& operator=(const WorkerThread&);

public:
    void Run();

private:
    BufferQueuePtr& mTaskQueue;
}; //class WorkerThread
typedef std::tr1::shared_ptr<WorkerThread> WorkerThreadPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_WORKERTHREAD_H
