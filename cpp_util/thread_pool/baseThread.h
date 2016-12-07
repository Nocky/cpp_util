#ifndef CPP_UTIL_THREAD_POOL_BASETHREAD_H
#define CPP_UTIL_THREAD_POOL_BASETHREAD_H

#include <pthread.h>
#include "common/common.h"
#include "nonCopyable.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class BaseThread: public NonCopyable {
public:
    BaseThread();
    virtual ~BaseThread();

private:
    BaseThread(const BaseThread&);
    BaseThread& operator=(const BaseThread&);

private:
    /*
     * 1. thread start function must be a static
     * */
    static void* WorkFun(void* baseThread);

public:
    virtual void Run()=0;
    void Start();
    void Join();
     
private:
    pthread_t mThreadId;
    bool mIsStart;
    bool mIsJoin;
}; //class BaseThread
typedef std::tr1::shared_ptr<BaseThread> BaseThreadPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_BASETHREAD_H
