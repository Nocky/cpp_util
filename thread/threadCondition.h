#ifndef CPP_UTIL_THREAD_CONDITION_H
#define CPP_UTIL_THREAD_CONDITION_H

#include <tr1/memory>
#include "mutexLock.h"

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
}; //class ThreadCondition
typedef std::tr1::shared_ptr<ThreadCondition> ThreadConditionPtr;

} //namespace Util
#endif //CPP_UTIL_THREAD_ARGVCONTENTEXT_H
