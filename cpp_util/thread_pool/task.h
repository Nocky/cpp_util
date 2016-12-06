#ifndef CPP_UTIL_THREAD_POOL_TASK_H
#define CPP_UTIL_THREAD_POOL_TASK_H
#include "common/common.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class Task {
public:
    Task();
    virtual ~Task();

public:
    virtual void Run() = 0;
}; //class Task
typedef std::tr1::shared_ptr<Task> TaskPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_TASK_H
