#ifndef CPPUTIL_CPP_UTIL_THREADPOOL_H
#define CPPUTIL_CPP_UTIL_THREADPOOL_H

#include "thread.h"
#include "non_copyable.h"
#include "blocking_queue.h"
#include "bounded_blocking_queue.h"

namespace Util {

class Task {
public:
    Task();
    virtual ~Task();

public:
    virtual void Run() = 0;
};

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
                Task* task = mThreadPool->mTaskQueue.Pop();
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

} //end namespace Util
#endif //CPPUTIL_CPP_UTIL_THREADPOOL_H
