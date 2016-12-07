#include <assert.h>
#include "common/common.h"
#include "mutexLock.h"
#include "condition.h"
#include "task.h"
#include "bufferQueue.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

BufferQueue::BufferQueue(size_t maxSize) 
    :mSize(maxSize),
    mEmptyCondition(mMutexLock),
    mFullCondition(mMutexLock) {
    assert(maxSize);
}

BufferQueue::~BufferQueue() {
}

void BufferQueue::Push(Task* task) {
    mMutexLock.Lock();
    while (mQueue.size() >= mSize) {
        mEmptyCondition.Wait();
    }
    mQueue.push(task);
    mMutexLock.UnLock();
    mFullCondition.Notify();
}

Task* BufferQueue::Pop() {
    mMutexLock.Lock();
    while (mQueue.empty()) {
        mFullCondition.Wait();
    }
    Task* task = mQueue.front();
    mQueue.pop();
    mMutexLock.UnLock();
    mEmptyCondition.Notify();
    return task;
}

NAMESPACE_END(Util)
