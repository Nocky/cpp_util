#ifndef CPP_UTIL_THREAD_THREADPOOL_H
#define CPP_UTIL_THREAD_THREADPOOL_H

#include <tr1/memory> 
#include "cpp_util/common/common.h"
#include "thread.h"
#include "nonCopyable.h"
#include "blockingQueue.h"
#include "boundedBlockingQueue.h"

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

class ThreadPool: public NonCopyable {
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
    void AddTask(Task* task);

private:
    friend class Worker;

private:
    vector<Thread*> mThreadVec;
    BoundedBlockingQueue<Task*> mTaskQueue;
}; //class ThreadPool
typedef std::tr1::shared_ptr<ThreadPool*> ThreadPoolPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_THREADPOOL_H
