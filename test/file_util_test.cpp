#include <gtest/gtest.h>
#include <string.h>
#include "file_util.h"

using namespace std;
using namespace Util;

TEST(TestFileLock, Read) {
    string fileName = "./testdata/file_util_test";
    string content = "";
    ASSERT_TRUE(FileUtil::Read(fileName, content));
    cout << content << endl;

    fileName = "./testdata/file_util_test2";
    content = "";
    ASSERT_FALSE(FileUtil::Read(fileName, content));
}
