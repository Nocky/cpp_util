#include <gtest/gtest.h>
#include "argvContext.h"
#include "common.h"

USING_NAMESPACE(Util)

TEST(TestArgvContext, ArgvContext) {
    const int argc = 8; 
    const char* const argv[] = {
        "submit",
        "test.sh",
        "-name",
        "chenguolin",
        "--age",
        "18",
        "text",
        "help"
    };
    ArgvContext argvContext(argc, argv);
    cout << argvContext << endl;
    // test HasOption
    const string key = "name";
    ASSERT_TRUE(argvContext.HasOption(key));
    // test operator
    ASSERT_EQ(argvContext[1], "test.sh");
    ASSERT_EQ(argvContext[2], "text");
    ASSERT_EQ(argvContext[3], "help");
    //ASSERT_EQ(argvContext[2], "test");
    ASSERT_EQ(argvContext["age"], "18");
    ASSERT_EQ(argvContext["name"], "chenguolin");
}
