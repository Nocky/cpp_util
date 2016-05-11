#include <assert.h>
#include "thread.h"

namespace Util {

Thread::Thread()
    :mIsStart(false), 
    mIsJoin(false) {
}

Thread::~Thread() {
    if(mIsStart && !mIsJoin) {
        assert(!pthread_detach(mThreadId));
    }
}

void Thread::Start() {
    assert(!mIsStart);
    assert(!pthread_create(&mThreadId, NULL, Worker, (void*)this));
    mIsStart = true;
}

void Thread::Join() { 
    assert(!mIsJoin);
    assert(!pthread_join(mThreadId, NULL));
    mIsJoin = true;
}

void* Thread::Worker(void* threadPtr) {
    Thread* ptr = (Thread*)threadPtr;
    ptr->Run();
    return NULL;
}

} //end namespace Util
