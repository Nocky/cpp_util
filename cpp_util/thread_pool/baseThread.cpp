#include <assert.h>
#include "common/common.h"
#include "baseThread.h"

NAMESPACE_SETUP(Util)

BaseThread::BaseThread()
    :mIsStart(false), 
    mIsJoin(false) {
}

BaseThread::~BaseThread() {
    assert(mIsStart && mIsJoin);
    assert(!pthread_detach(mThreadId));
}

void BaseThread::Start() {
    assert(!mIsStart);
    assert(!pthread_create(&mThreadId, NULL, WorkFun, (void*)this));
    mIsStart = true;
}

void BaseThread::Join() { 
    assert(!mIsJoin);
    assert(!pthread_join(mThreadId, NULL));
    mIsJoin = true;
}

void* BaseThread::WorkFun(void* baseThread) {
    BaseThread* ptr = (BaseThread*)baseThread;
    ptr->Run();
    return NULL;
}

NAMESPACE_END(Util)
