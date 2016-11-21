#include "cpp_util/common/common.h"
#include "threadPool.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

ThreadPool::ThreadPool(size_t threadNum, size_t queueMaxSize)
    :mThreadVec(threadNum),
    mTaskQueue(queueMaxSize) {
    assert(threadNum);
    assert(queueMaxSize);
    for(size_t i = 0; i < threadNum; i++) {
        mThreadVec[i] = new Worker(this);
    }
}

ThreadPool::~ThreadPool() {
    size_t threadSize = mThreadVec.size();
    for(size_t i = 0; i < threadSize; i++) {
        mTaskQueue.Push(NULL);
    }
    for(size_t i = 0; i < threadSize; i++) {
        mThreadVec[i]->Join();
        delete mThreadVec[i];
    }
}

void ThreadPool::Start() {
    size_t threadSize = mThreadVec.size();
    for(size_t i = 0; i < threadSize; i++) {
        mThreadVec[i]->Start();
    }
}

void ThreadPool::AddTask(Task* task) {
    assert(task);
    mTaskQueue.Push(task);
}

NAMESPACE_END(Util)
