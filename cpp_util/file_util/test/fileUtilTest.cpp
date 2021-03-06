#include <string.h>
#include <gtest/gtest.h>
#include "fileUtil.h"

using namespace std;
using namespace Util;

TEST(TestFileUtil, Read) {
    string fileName = "./testdata/file_util_test";
    string content = "";
    ASSERT_TRUE(FileUtil::Read(fileName, content));

    vector<string> lineVec;
    fileName = "./testdata/file_util_test";
    ASSERT_TRUE(FileUtil::Read(fileName, lineVec));
    ASSERT_EQ((size_t)348982, lineVec.size());

    fileName = "./testdata/file_util_test2";
    content = "";
    ASSERT_FALSE(FileUtil::Read(fileName, content));

    fileName = "./testdata/file_util_test2";
    ASSERT_FALSE(FileUtil::Read(fileName, lineVec));
    ASSERT_EQ((size_t)0, lineVec.size());

    fileName = "./testdata/user.dict.utf8";
    ASSERT_TRUE(FileUtil::Read(fileName, lineVec));
    ASSERT_EQ((size_t)1, lineVec.size());

    fileName = "./testdata/file_util_test";
    ASSERT_TRUE(FileUtil::Read(fileName, lineVec));
    ASSERT_EQ((size_t)348982, lineVec.size());
}

TEST(TestFileUtil, Write) {
    string fileName = "./testdata/write_file";
    string content = "testwrite\n";
    ASSERT_TRUE(FileUtil::Write(fileName, content));

    string content2 = "testwrite 2\n";
    ASSERT_TRUE(FileUtil::Write(fileName, content2, true));
}
