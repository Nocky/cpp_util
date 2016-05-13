#ifndef CPP_UTIL_THREAD_THREAD_H
#define CPP_UTIL_THREAD_THREAD_H

#include <pthread.h>
#include "thread/nonCopyable.h"

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
}; //class Thread

} //namespace Util
#endif //CPP_UTIL_THREAD_THREAD_H
