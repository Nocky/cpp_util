#ifndef SIMHASH_SERVER_INCLUDE_UTIL_CONDITION_H
#define SIMHASH_SERVER_INCLUDE_UTIL_CONDITION_H

#include "include/util/mutex_lock.h"

using namespace std;
namespace Util {

class ThreadCondition: public NonCopyable {
public:
    explicit ThreadCondition(MutexLock& mutexLock);
    virtual ~ThreadCondition();

public:
    void Wait();
    void Notify();
    void NotifyAll();

private:
    MutexLock& mMutexLock;
    pthread_cond_t mPcond;
};

} //end Util namespace
#endif //SIMHASH_SERVER_INCLUDE_UTIL_ARGVCONTENTEXT_H
