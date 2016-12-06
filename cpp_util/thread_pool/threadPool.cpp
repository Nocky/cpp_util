#include "common/common.h"
#include "task.h"
#include "workerThread.h"
#include "threadPool.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

ThreadPool::ThreadPool(size_t threadNum, size_t taskQueueSize)
    :mWorkerThreadNum(threadNum),
    mTaskBufferQueueSize(taskQueueSize),
    mTaskBufferQueue(taskQueueSize) {
    assert(threadNum);
    assert(taskQueueSize);
    assert(mTaskBufferQueue);
    // init mThreadVec
    for(size_t i = 0; i < threadNum; i++) {
        mWorkerThreadVec[i].reset(new Worker(mTaskBufferQueue));
    }
}

ThreadPool::~ThreadPool() {
    for(size_t i = 0; i < mWorkerThreadNum; i++) {
        mThreadVec[i]->Join();
    }
}

void ThreadPool::Start() {
    for(size_t i = 0; i < mWorkerThreadNum; i++) {
        mThreadVec[i]->Start();
    }
}

void ThreadPool::AddTask(TaskPtr& task) {
    assert(task);
    mTaskBufferQueue.Push(task);
}

NAMESPACE_END(Util)
