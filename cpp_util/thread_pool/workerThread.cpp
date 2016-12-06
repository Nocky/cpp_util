#include "common/common.h"
#include "task.h"
#include "bufferQueue.h"
#include "workerThread.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

WorkerThread::WorkerThread(BufferQueuePtr& taskQueue) {
    mTaskQueue = taskQueue;
}

WorkerThread::~WorkerThread() {
}

void WorkerThread::Run() {
    while(true) {
        TaskPtr task = mTaskQueue->Pop();
        if(NULL == task) {
            break;
        }
        task->Run();
    }
}

NAMESPACE_END(Util)
