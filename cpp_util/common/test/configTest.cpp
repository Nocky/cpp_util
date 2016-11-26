#include <gtest/gtest.h>
#include "config.h"
#include "common.h"

USING_NAMESPACE(Util)

TEST(TestConfig, LoadFile) {
    string filePath = "testdata/config";
    Config config(filePath);
    config.LoadFile();
    cout << config.GetConfigInfo() << endl;

    filePath = "testdata/config.fail";
    Config config2(filePath);
    config2.LoadFile();
    cout << config2.GetConfigInfo() << endl;
}

TEST(TestConfig, HasKey) {
    string filePath = "testdata/config";
    Config config(filePath);
    config.LoadFile();
    ASSERT_TRUE(config.HasKey("name"));
    ASSERT_FALSE(config.HasKey("Name"));
}

TEST(TestConfig, GetValue) {
    string filePath = "testdata/config";
    Config config(filePath);
    config.LoadFile();

    string value = "";
    ASSERT_TRUE(config.GetValue("name", value));
    ASSERT_EQ(value, "chenguolin");

    value = "";
    ASSERT_FALSE(config.GetValue("Name", value));
    ASSERT_EQ(value, "");

    int age = 0;
    ASSERT_TRUE(config.GetValue("age", age));
    ASSERT_EQ(age, 18);
    
    ASSERT_FALSE(config.GetValue("Age", age));
}

TEST(TestConfig, Operator) {
    string filePath = "testdata/config";
    Config config(filePath);
    config.LoadFile();

    string key = "";
    const char* ptr = config[key.c_str()];
    ASSERT_EQ(NULL, ptr);

    key = "Name";
    ptr = config[key.c_str()];
    ASSERT_EQ(NULL, ptr);

    key = "name";
    ptr = config[key.c_str()];
    ASSERT_EQ(string(ptr), "chenguolin");
}

TEST(TestConfig, GetConfigInfo) {
    string filePath = "testdata/config";
    Config config(filePath);
    config.LoadFile();
    string configInfo = "";
    configInfo = config.GetConfigInfo();
    cout << configInfo << endl;
    ASSERT_EQ(configInfo, "{age:18, file:config, name:chenguolin}");
}
