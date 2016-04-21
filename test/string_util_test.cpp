#include <gtest/gtest.h>
#include "string_util.h"

using namespace Util;
using namespace std;

TEST(TestStringUtil, StringFormat){
	// empty va list
	string res = "";
	const char* format = "";
	ASSERT_TRUE(StringUtil::StringFormat(res, format));
	ASSERT_EQ(res, "");

	// non empty va list
	res = "";
	format = "name:%s, age:%d";
	ASSERT_TRUE(StringUtil::StringFormat(res, format, "chenguolin", 18));
	ASSERT_EQ(res, "name:chenguolin, age:18");
}

TEST(TestStringUtil, StringFormat2){
	// empty va list
	string res = "";
	const char* format = "";
	ASSERT_EQ(StringUtil::StringFormat(format), "");
	
	// non empty va list
	res = "";
	format = "name:%s, age:%d";
	ASSERT_EQ(StringUtil::StringFormat(format, "chenguolin", 18), "name:chenguolin, age:18");
	
}

TEST(TestStringUtil, Join){
	// Join vector
	vector<int> vec1;
	string str1 = "";
	vector<int>::iterator begin1 = vec1.begin();
	vector<int>::iterator end1 = vec1.end();
	ASSERT_TRUE(StringUtil::Join(begin1, end1, str1, "+"));
	ASSERT_EQ(str1, "");

	vector<int> vec2(2,100);
	string str2 = "";
	vector<int>::iterator begin2 = vec2.begin();
	vector<int>::iterator end2 = vec2.end();
	ASSERT_TRUE(StringUtil::Join(begin2, end2, str2, "+"));
	ASSERT_EQ(str2, "100+100");

	// Join map
	map<string, int>mp1;
	str1 = "";
	map<string, int>::iterator begin3 = mp1.begin();
	map<string, int>::iterator end3 = mp1.end();
	ASSERT_TRUE(StringUtil::Join(begin3, end3, str1, "+"));
	ASSERT_EQ(str1, "");

	map<string, int>mp2;
	mp2.insert(make_pair<string, int>("one", 1));
	mp2.insert(make_pair<string, int>("two", 2));
	str2 = "";
	map<string, int>::iterator begin4 = mp2.begin();
	map<string, int>::iterator end4 = mp2.end();
	ASSERT_TRUE(StringUtil::Join(begin4, end4, str2, "+"));
	ASSERT_EQ(str2, "one:1+two:2");
}

TEST(TestStringUtil, Join2){
	// Join vector
	vector<int> vec1;
	vector<int>::iterator begin1 = vec1.begin();
	vector<int>::iterator end1 = vec1.end();
	ASSERT_EQ(StringUtil::Join(begin1, end1, "+"), "");

	vector<int> vec2(2,100);
	vector<int>::iterator begin2 = vec2.begin();
	vector<int>::iterator end2 = vec2.end();
	ASSERT_EQ(StringUtil::Join(begin2, end2, "+"), "100+100");

	// Join map
	map<string, int>mp1;
	map<string, int>::iterator begin3 = mp1.begin();
	map<string, int>::iterator end3 = mp1.end();
	ASSERT_EQ(StringUtil::Join(begin3, end3, "+"), "");

	map<string, int>mp2;
	mp2.insert(make_pair<string, int>("one", 1));
	mp2.insert(make_pair<string, int>("two", 2));
	map<string, int>::iterator begin4 = mp2.begin();
	map<string, int>::iterator end4 = mp2.end();
	ASSERT_EQ(StringUtil::Join(begin4, end4, "+"), "one:1+two:2");
}

TEST(TestStringUtil, Split){
	// empty string
	string str = "";
	vector<string> vec;
	ASSERT_FALSE(StringUtil::Split(str, vec, "&&"));

	str = "";
	ASSERT_FALSE(StringUtil::Split(str, vec, "&&", true));

	// non empty string
	str = "aa";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)1, vec.size());
	ASSERT_EQ("aa", vec[0]);

	str = "aa&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)1, vec.size());
	ASSERT_EQ("aa", vec[0]);

	str = "&&aa";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)1, vec.size());
	ASSERT_EQ("aa", vec[0]);

	str = "&&aa&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)1, vec.size());
	ASSERT_EQ("aa", vec[0]);

	str = "aa";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)1, vec.size());
	ASSERT_EQ("aa", vec[0]);

	str = "aa&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)1, vec.size());
	ASSERT_EQ("aa", vec[0]);

	str = "&&aa";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)2, vec.size());
	ASSERT_EQ("", vec[0]);
	ASSERT_EQ("aa", vec[1]);

	str = "&&aa&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)2, vec.size());
	ASSERT_EQ("", vec[0]);
	ASSERT_EQ("aa", vec[1]);

	str = "aa&&bb&&cc";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "aa&&bb&&cc&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "&&aa&&bb&&cc";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "&&aa&&bb&&cc&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "aa&&bb&&cc";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "aa&&bb&&cc&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);
	
	str = "&&aa&&bb&&cc";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)4, vec.size());
	ASSERT_EQ("", vec[0]);
	ASSERT_EQ("aa", vec[1]);
	ASSERT_EQ("bb", vec[2]);
	ASSERT_EQ("cc", vec[3]);

	str = "&&aa&&bb&&cc&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)4, vec.size());
	ASSERT_EQ("", vec[0]);
	ASSERT_EQ("aa", vec[1]);
	ASSERT_EQ("bb", vec[2]);
	ASSERT_EQ("cc", vec[3]);

	str = "aa&&bb&&cc&&&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "&&&&aa&&bb&&cc&&&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&"));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);

	str = "aa&&bb&&cc&&&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)4, vec.size());
	ASSERT_EQ("aa", vec[0]);
	ASSERT_EQ("bb", vec[1]);
	ASSERT_EQ("cc", vec[2]);
	ASSERT_EQ("", vec[3]);

	str = "&&&&aa&&bb&&cc&&&&";
	ASSERT_TRUE(StringUtil::Split(str, vec, "&&", true));
	ASSERT_EQ((size_t)6, vec.size());
	ASSERT_EQ("", vec[0]);
	ASSERT_EQ("", vec[1]);
	ASSERT_EQ("aa", vec[2]);
	ASSERT_EQ("bb", vec[3]);
	ASSERT_EQ("cc", vec[4]);
	ASSERT_EQ("", vec[5]);
}

TEST(TestStringUtil, Upper){
    // empty string
    string str = "";
    StringUtil::Upper(str);
    ASSERT_EQ(str, "");

    // non empty string
    str = "unit test";
    StringUtil::Upper(str);
    ASSERT_EQ(str, "UNIT TEST");

    str = "Unit Test";
    StringUtil::Upper(str);
    ASSERT_EQ(str, "UNIT TEST");
}

TEST(TestStringUtil, Lower){
    // empty string
    string str = "";
    StringUtil::Lower(str);
    ASSERT_EQ(str, "");

    // non empty string
    str = "UNIT TEST";
    StringUtil::Lower(str);
    ASSERT_EQ(str, "unit test");

    str = "UnIT TesT";
    StringUtil::Lower(str);
    ASSERT_EQ(str, "unit test");
}

TEST(TestStringUtil, Ltrim){
    string str = "";
    str = StringUtil::Ltrim(str);
    ASSERT_EQ(str, "");

    str = "chen guolin";
    str = StringUtil::Ltrim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "       chen guolin";
    str = StringUtil::Ltrim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "       chen guolin    ";
    str = StringUtil::Ltrim(str);
    ASSERT_EQ(str, "chen guolin    ");

    str = "                 ";
    str = StringUtil::Ltrim(str);
    ASSERT_EQ(str, "");

    str = "";
    str = StringUtil::Ltrim(str, 'h');
    ASSERT_EQ(str, "");

    str = "chen guolin";
    str = StringUtil::Ltrim(str, 'h');
    ASSERT_EQ(str, "chen guolin");

    str = "hhh    chen guolin";
    str = StringUtil::Ltrim(str, 'h');
    ASSERT_EQ(str, "    chen guolin");

    str = "hhhhhhchen guolin    ";
    str = StringUtil::Ltrim(str, 'h');
    ASSERT_EQ(str, "chen guolin    ");

    str = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
    str = StringUtil::Ltrim(str, 'h');
    ASSERT_EQ(str, "");
}

TEST(TestStringUtil, Rtrim){
    string str = "";
    str = StringUtil::Rtrim(str);
    ASSERT_EQ(str, "");

    str = "chen guolin";
    str = StringUtil::Rtrim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "chen guolin      ";
    str = StringUtil::Rtrim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "    chen guolin    ";
    str = StringUtil::Rtrim(str);
    ASSERT_EQ(str, "    chen guolin");

    str = "                  ";
    str = StringUtil::Rtrim(str);
    ASSERT_EQ(str, "");

    str = "";
    str = StringUtil::Rtrim(str, 'h');
    ASSERT_EQ(str, "");

    str = "chen guolin";
    str = StringUtil::Rtrim(str, 'h');
    ASSERT_EQ(str, "chen guolin");

    str = "chen guolin      hhhhhh";
    str = StringUtil::Rtrim(str, 'h');
    ASSERT_EQ(str, "chen guolin      ");

    str = "chen guolinhhhhhhhhhhhhhh";
    str = StringUtil::Rtrim(str, 'h');
    ASSERT_EQ(str, "chen guolin");

    str = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
    str = StringUtil::Rtrim(str, 'h');
    ASSERT_EQ(str, "");
}

TEST(TestStringUtil, Trim){
    string str = "";
    str = StringUtil::Trim(str);
    ASSERT_EQ(str, "");

    str = "chen guolin";
    str = StringUtil::Trim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "chen guolin      ";
    str = StringUtil::Trim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "    chen guolin    ";
    str = StringUtil::Trim(str);
    ASSERT_EQ(str, "chen guolin");

    str = "                  ";
    str = StringUtil::Trim(str);
    ASSERT_EQ(str, "");

    str = "";
    str = StringUtil::Trim(str, 'h');
    ASSERT_EQ(str, "");

    str = "chen guolin";
    str = StringUtil::Trim(str, 'h');
    ASSERT_EQ(str, "chen guolin");

    str = "chen guolin      hhhhhh";
    str = StringUtil::Trim(str, 'h');
    ASSERT_EQ(str, "chen guolin      ");

    str = "chen guolinhhhhhhhhhhhhhh";
    str = StringUtil::Trim(str, 'h');
    ASSERT_EQ(str, "chen guolin");

    str = "hhhhhhhhhhhhhhhhhhhhhhchen guolinhhhhhhhhhhhhhh";
    str = StringUtil::Trim(str, 'h');
    ASSERT_EQ(str, "chen guolin");

    str = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
    str = StringUtil::Trim(str, 'h');
    ASSERT_EQ(str, "");
}

TEST(TestStringUtil, StartsWith){
    string str = "";
    string prefix = "";
    ASSERT_TRUE(StringUtil::StartsWith(str, prefix));

    str = "chen";
    prefix = "";
    ASSERT_TRUE(StringUtil::StartsWith(str, prefix));

    str = "";
    prefix = "chen";
    ASSERT_FALSE(StringUtil::StartsWith(str, prefix));

    str = "chenguolin";
    prefix = "chen";
    ASSERT_TRUE(StringUtil::StartsWith(str, prefix));

    str = "chenguolin";
    prefix = "chne";
    ASSERT_FALSE(StringUtil::StartsWith(str, prefix));
}

TEST(TestStringUtil, EndsWith){
    string str = "";
    string suffix = "";
    ASSERT_TRUE(StringUtil::EndsWith(str, suffix));

    str = "chen";
    suffix = "";
    ASSERT_TRUE(StringUtil::EndsWith(str, suffix));

    str = "";
    suffix = "chen";
    ASSERT_FALSE(StringUtil::EndsWith(str, suffix));

    str = "chenguolin";
    suffix = "lin";
    ASSERT_TRUE(StringUtil::EndsWith(str, suffix));

    str = "chenguolin";
    suffix = "lni";
    ASSERT_FALSE(StringUtil::EndsWith(str, suffix));
}

TEST(TestStringUtil, IsInStr){
    string str = "";
    char x = ' ';
    ASSERT_FALSE(StringUtil::IsInStr(str, x)); 

    str = " ";
    x = ' ';
    ASSERT_TRUE(StringUtil::IsInStr(str, x)); 

    str = " chenguo lin ";
    x = 'g';
    ASSERT_TRUE(StringUtil::IsInStr(str, x)); 

    str = " chenguo lin ";
    x = 'G';
    ASSERT_FALSE(StringUtil::IsInStr(str, x)); 
}

TEST(TestStringUtil, TwoCharToUint16){
    char high = 'a';
    char low = 'A';
    uint16_t value = StringUtil::TwoCharToUint16(high, low);
    ASSERT_EQ((uint16_t)24897, value);
}

TEST(TestStringUtil, GetCurrentTime) {
    string nowTimeStr = StringUtil::GetCurrentTime();
    cout << nowTimeStr << endl;

    nowTimeStr = StringUtil::GetCurrentTime("%Y-%m-%d");
    cout << nowTimeStr << endl;
}

TEST(TestStringUtil, CodeConverter) {
    // case 1
    const char* fromCharset = NULL; 
    const char* toCharset = NULL; 
    string srcStr = "";
    string desStr = "";
    ASSERT_FALSE(StringUtil::CodeCharsetConverter(fromCharset, toCharset, srcStr, desStr));

    fromCharset = NULL; 
    toCharset = "gb2312"; 
    srcStr = "";
    desStr = "";
    ASSERT_FALSE(StringUtil::CodeCharsetConverter(fromCharset, toCharset, srcStr, desStr));

    fromCharset = "utf-8"; 
    toCharset = NULL; 
    srcStr = "";
    desStr = "";
    ASSERT_FALSE(StringUtil::CodeCharsetConverter(fromCharset, toCharset, srcStr, desStr));

    fromCharset = "utf-8"; 
    toCharset = "unicode"; 
    srcStr = "正在安装";
    desStr = "";
    ASSERT_TRUE(StringUtil::CodeCharsetConverter(fromCharset, toCharset, srcStr, desStr));

    fromCharset = "unicode"; 
    toCharset = "utf-8"; 
    srcStr = desStr;
    desStr = "";
    ASSERT_TRUE(StringUtil::CodeCharsetConverter(fromCharset, toCharset, srcStr, desStr));
    ASSERT_EQ(desStr, "正在安装");

    fromCharset = "utf-8"; 
    toCharset = "utf-8"; 
    srcStr = "chenguolin";
    desStr = "";
    ASSERT_TRUE(StringUtil::CodeCharsetConverter(fromCharset, toCharset, srcStr, desStr));
    ASSERT_EQ(desStr, "chenguolin");
}

