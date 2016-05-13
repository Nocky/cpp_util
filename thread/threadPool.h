#ifndef CPP_UTIL_THREAD_THREADPOOL_H
#define CPP_UTIL_THREAD_THREADPOOL_H

#include "thread/thread.h"
#include "thread/nonCopyable.h"
#include "thread/blockingQueue.h"
#include "thread/boundedBlockingQueue.h"

using namespace std;
namespace Util {

class Task {
public:
    Task();
    virtual ~Task();

public:
    virtual void Run() = 0;
}; //class Task

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

} //namespace Util
#endif //CPP_UTIL_THREAD_THREADPOOL_H
