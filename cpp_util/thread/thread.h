#ifndef CPP_UTIL_THREAD_THREAD_H
#define CPP_UTIL_THREAD_THREAD_H

#include <pthread.h>
#include <tr1/memory>
#include "nonCopyable.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class Thread: public NonCopyable {
public:
    Thread();
    virtual ~Thread();

private:
    /*
     * 1. thread start function must be a static
     * */
    static void* Worker(void* threadPtr);

public:
    virtual void Run()=0;
    void Start();
    void Join();
     
private:
    pthread_t mThreadId;
    bool mIsStart;
    bool mIsJoin;
}; //class Thread
typedef std::tr1::shared_ptr<Thread> ThreadPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_THREAD_H
