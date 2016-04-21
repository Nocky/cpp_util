#ifndef CPPUTIL_CPP_UTIL_THREAD_H
#define CPPUTIL_CPP_UTIL_THREAD_H

#include <pthread.h>
#include "non_copyable.h"

using namespace std;

namespace Util {

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
};

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_THREAD_H
