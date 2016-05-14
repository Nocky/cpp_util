#include <gtest/gtest.h>
#include "thread/thread.h"

using namespace std;
using namespace Util;

class TestThread: public Thread {
public:
    void Run();

public:
    static int value;
};

int TestThread::value = 0;

void TestThread::Run() {
    cout << "Run function" << endl;
    value++;
}

TEST(TestThread, Thread) {
    // case 1
    TestThread testThread;
    testThread.Start(); 
    sleep(1);  //sleep 1s, 保证子线程能够执行
    ASSERT_EQ(TestThread::value, 1);
    
    // case 2
    TestThread testThread2;
    testThread2.Start(); 
    testThread2.Join(); //显示阻塞主线程,等待子线程结束 
    ASSERT_EQ(TestThread::value, 2);
}
