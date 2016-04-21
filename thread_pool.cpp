#ifndef LIMONP_THREAD_POOL_HPP
#define LIMONP_THREAD_POOL_HPP

#include "thread_pool.h"

using namespace std;
namespace Util {

ThreadPool::ThreadPool(size_t threadNum, size_t queueMaxSize) {
    assert(threadNum);
    assert(queueMaxSize);
    mThreadVec(threadNum);
    mTaskQueue(queueMaxSize);
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

void ThreadPool::Add(Task* task) {
    assert(task);
    mTaskQueue.Push(task);
}

} //end Util namespace
