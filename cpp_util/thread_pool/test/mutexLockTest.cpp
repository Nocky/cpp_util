#include <gtest/gtest.h>
#include "thread/mutexLock.h"
#include "thread/thread.h"

using namespace std;
using namespace Util;

class MutexTestThread: public Thread {
public:
    void Run();

public:
    static int value;
    static MutexLock mMutexLock;
};

int MutexTestThread::value = 0;
MutexLock MutexTestThread::mMutexLock;

void MutexTestThread::Run() {
    MutexLockGuard mutexLockGuard(mMutexLock);
    cout << "Run function" << endl;
    cout << value++ << endl;
}

TEST(TestMutexLock, MutexLockGuard) {
    MutexLock mutexLock;
    MutexLockGuard mutexLockGuard(mutexLock);
}

TEST(TestMutexLock, CreateThread) {
    MutexTestThread threadArr[5];
    for (size_t i = 0; i < 5; ++i) {
        threadArr[i].Start();
    }
    for (size_t i = 0; i < 5; ++i) {
        threadArr[i].Join();
    }
}
