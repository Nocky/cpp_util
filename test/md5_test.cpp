#include <gtest/gtest.h>
#include "md5.h"

using namespace Util;
using namespace std;

TEST(TestMd5, Md5String){
	// hash NULL ptr 
	char* str = NULL;
	string hashVal = "";
	ASSERT_FALSE(Md5String(str, hashVal));
	ASSERT_EQ(hashVal, "");

	// hash empty string
	string val = "";
	hashVal = "";
	ASSERT_TRUE(Md5String(val.c_str(), hashVal));
	ASSERT_EQ(hashVal, "d41d8cd98f00b204e9800998ecf8427e");

	// hash nonempty string
	val = "chenguolin";
	hashVal = "";
	ASSERT_TRUE(Md5String(val.c_str(), hashVal));
	ASSERT_EQ(hashVal, "d1dfa0e4bcdefec583b9a11fb7a0f806");
}

TEST(TestMd5, Md5File){
	// hash NULL ptr 
	char* filePathPtr = NULL;
	string hashVal = "";
	ASSERT_FALSE(Md5File(filePathPtr, hashVal));
	ASSERT_EQ(hashVal, "");

	// hash empty filePath
	string filePath = "";
	hashVal = "";
	ASSERT_FALSE(Md5File(filePath.c_str(), hashVal));
	ASSERT_EQ(hashVal, "");

	// hash nonempty filePath
	filePath = "testdata/test_1";
	hashVal = "";
	ASSERT_TRUE(Md5File(filePath.c_str(), hashVal));
	ASSERT_EQ(hashVal, "fd35e9b80d13dece09300e31f10f256b");

	// hash nonempty filePath
	filePath = "testdata/test_2";
	hashVal = "";
	ASSERT_TRUE(Md5File(filePath.c_str(), hashVal));
	ASSERT_EQ(hashVal, "96fb54c6cafb4b1425d85fd6e2d4f228");
}
