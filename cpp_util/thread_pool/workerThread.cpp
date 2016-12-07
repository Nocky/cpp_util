#include "common/common.h"
#include "task.h"
#include "bufferQueue.h"
#include "workerThread.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

WorkerThread::WorkerThread(BufferQueuePtr& taskQueue)
    :mTaskQueue(taskQueue) {
}

WorkerThread::~WorkerThread() {
}

void WorkerThread::Run() {
    while(true) {
        Task* task = mTaskQueue->Pop();
        if(NULL == task) {
            break;
        }
        task->Run();
        DELETE_AND_SET_NULL(task);
    }
}

NAMESPACE_END(Util)
