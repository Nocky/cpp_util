#include <gtest/gtest.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <common/fileLock.h>

using namespace std;
using namespace Util;

TEST(TestFileLock, FileLock) {
    string fileName = "./testdata/file_lock_test";
    FileLock fileLock(fileName);
    string errorMessage = "";
    ASSERT_TRUE(fileLock.Lock(errorMessage));
    cout << "Lock Error:" << errorMessage << endl;
    ASSERT_TRUE(fileLock.UnLock(errorMessage));
    cout << "UnLock Error:" << errorMessage << endl;
}

TEST(TestFileLock, FileLock2) {
    string fileName = "./testdata/file_lock_test";
    FileLock fileLock(fileName);
    string errorMessage = "";
    ASSERT_TRUE(fileLock.Lock(errorMessage));
    int fd = open(fileName.c_str(), O_RDWR | O_CREAT, 0644);
    char buffer[16] = "file_lock";
    size_t count = 16;
    write(fd, buffer, count);
    cout << "Lock Error:" << errorMessage << endl;
    ASSERT_TRUE(fileLock.UnLock(errorMessage));
    cout << "UnLock Error:" << errorMessage << endl;
}
