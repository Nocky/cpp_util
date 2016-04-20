#ifndef SIMHASH_SERVER_INCLUDE_UTIL_THREADPOOL_H
#define SIMHASH_SERVER_INCLUDE_UTIL_THREADPOOL_H

#include "include/util/thread.h"
#include "include/util/non_copyable.h"
#include "include/util/blocking_queue.h"
#include "include/util/bounded_blocking_queue.h"

namespace Util {

class Task {
public:
    Task();
    virtual ~Task();

public:
    virtual void Run() = 0;
}; //end Class Task

template <typename TaskType, typename ArgType>
Task* CreateTask(ArgType arg) {
    return new TaskType(arg);
}

template <typename TaskType, typename ArgType0, typename ArgType1>
Task* CreateTask(ArgType0 arg0, ArgType1 arg1) {
    return new TaskType(arg0, arg1);
}

class ThreadPool: NonCopyable {
public:
    ThreadPool(size_t threadNum, size_t queueMaxSize);
    virtual ~ThreadPool();

private:
    class Worker: public Thread {
    public:
        Worker(ThreadPool* threadPool)
            :mThreadPool(threadPool) {
            assert(mThreadPool);
        }
        virtual ~Worker() {}

    public:
        // overload Run function
        void Run() {
            while(true) {
                Task* task = mThreadPool->mTaskQueue.pop();
                if(NULL == task) {
                    break;
                }
                task->Run();
                delete task;
            }
        }

    private:
        ThreadPool* mThreadPool;
    };

public:
    void Start();
    void AddTask(Task* task)

private:
    friend class Worker;

private:
    vector<Thread*> mThreadVec;
    BoundedBlockingQueue<Task*> mTaskQueue;
};

} //end Util namespace
#endif //SIMHASH_SERVER_INCLUDE_UTIL_THREADPOOL_H
