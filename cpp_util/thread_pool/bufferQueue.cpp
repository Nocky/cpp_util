#include <assert.h>
#include "common/common.h"
#include "task.h"
#include "mutexLock.h"
#include "condition.h"
#include "bufferQueue.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

BufferQueue::BufferQueue(size_t maxSize) 
    :mSize(maxSize),
    mEmptyCondition(mMutexLock),
    mFullCondition(mMutexLock),
    mQueue(maxSize, NULL){
    assert(maxSize);
}

void BufferQueue::Push(TaskPtr& task) {
    mMutexLock.Lock();
    while (mQueue.size() >= mSize) {
        mEmptyCondition.Wait();
    }
    mQueue.push(task);
    mMutexLock.UnLock();
    mFullCondition.Notify();
}

TaskPtr& BufferQueue::Pop() {
    mMutexLock.Lock();
    while (mQueue.empty()) {
        mFullCondition.Wait();
    }
    TaskPtr task = mQueue.pop();
    mMutexLock.UnLock();
    mEmptyCondition.Notify();
    return task;
}

NAMESPACE_END(Util)
