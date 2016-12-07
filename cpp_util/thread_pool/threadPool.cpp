#include <assert.h> 
#include "common/common.h"
#include "workerThread.h"
#include "task.h"
#include "threadPool.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

ThreadPool::ThreadPool(size_t threadNum, size_t bufferQueueSize)
    :mWorkerThreadNum(threadNum),
    mBufferQueueSize(bufferQueueSize),
    mBufferQueuePtr(new BufferQueue(bufferQueueSize)) {
    assert(threadNum);
    assert(bufferQueueSize);
    assert(mBufferQueuePtr);
    // init mWorkerThreadVec
    mWorkerThreadVec.resize(threadNum);
    for (size_t i = 0; i < threadNum; i++) {
        mWorkerThreadVec[i].reset(new WorkerThread(mBufferQueuePtr));
    }
}

ThreadPool::~ThreadPool() {
    for(size_t i = 0; i < mWorkerThreadNum; i++) {
        mWorkerThreadVec[i]->Join();
    }
}

void ThreadPool::Start() {
    for(size_t i = 0; i < mWorkerThreadNum; i++) {
        mWorkerThreadVec[i]->Start();
    }
}

void ThreadPool::AddTask(Task* task) {
    assert(task);
    mBufferQueuePtr->Push(task);
}

NAMESPACE_END(Util)
