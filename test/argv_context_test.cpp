#include <include/gtest/gtest.h>
#include "include/util/argv_context.h"

using namespace Util;

TEST(TestArgvContext, ArgvContext) {
    const int argc = 8; 
    const char* const argv[] = {
        "a.out",
        "test",
        "-name",
        "chenguolin",
        "--age",
        "18",
        "-h",
        "--help"
    };
    ArgvContext argvContext(argc, argv);
    cout << argvContext << endl;
    // test HasOption
    const string key = "-name";
    ASSERT_TRUE(argvContext.HasOption(key));
    // test operator
    ASSERT_EQ(argvContext[1], "test");
    //ASSERT_EQ(argvContext[2], "test");
    ASSERT_EQ(argvContext["--age"], "18");
    ASSERT_EQ(argvContext["-age"], "");
}
