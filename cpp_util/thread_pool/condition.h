#ifndef CPP_UTIL_THREAD_POOL_CONDITION_H
#define CPP_UTIL_THREAD_POOL_CONDITION_H

#include "common/common.h"
#include "mutexLock.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class Condition: public NonCopyable {
public:
    Condition(MutexLock& mutexLock);
    virtual ~Condition();

private:
    Condition(const Condition&);
    Condition& operator=(const Condition&);

public:
    void Wait();
    void Notify();

private:
    MutexLock& mMutexLock;
    pthread_cond_t mCond;
}; //class Condition
typedef std::tr1::shared_ptr<Condition> ConditionPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_CONDITION_H
