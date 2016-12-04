#include <gtest/gtest.h>
#include "common/localVector.h"
#include "stringUtil.h"

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

	str = "a b c";
	ASSERT_TRUE(StringUtil::Split(str, vec, " "));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("a", vec[0]);
	ASSERT_EQ("b", vec[1]);
	ASSERT_EQ("c", vec[2]);

	str = "a b c  ";
	ASSERT_TRUE(StringUtil::Split(str, vec, " "));
	ASSERT_EQ((size_t)3, vec.size());
	ASSERT_EQ("a", vec[0]);
	ASSERT_EQ("b", vec[1]);
	ASSERT_EQ("c", vec[2]);

	str = "a b c  ";
	ASSERT_TRUE(StringUtil::Split(str, vec, " ", true));
	ASSERT_EQ((size_t)4, vec.size());
	ASSERT_EQ("a", vec[0]);
	ASSERT_EQ("b", vec[1]);
	ASSERT_EQ("c", vec[2]);
	ASSERT_EQ("", vec[3]);
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

TEST(TestStringUtil, Utf8ToUnicode) {
    UnicodeContainer vec;
    char* ptr = NULL;
    size_t len = 0;
    ASSERT_FALSE(StringUtil::Utf8ToUnicode(ptr, len, vec));

    char ptr2[] = "陈国林";
    len = strlen(ptr2);
    vec.clear();
    ASSERT_TRUE(StringUtil::Utf8ToUnicode(ptr2, len, vec));
    ASSERT_EQ((size_t)3, vec.size());
    ASSERT_EQ((uint32_t)38472, vec[0]);
    ASSERT_EQ((uint32_t)22269, vec[1]);
    ASSERT_EQ((uint32_t)26519, vec[2]);

    string str = "陈国林";
    vec.clear();
    ASSERT_TRUE(StringUtil::Utf8ToUnicode(str, vec));
    ASSERT_EQ((size_t)3, vec.size());
    ASSERT_EQ((uint32_t)38472, vec[0]);
    ASSERT_EQ((uint32_t)22269, vec[1]);
    ASSERT_EQ((uint32_t)26519, vec[2]);

    string str2 = "·";
    vec.clear();
    ASSERT_TRUE(StringUtil::Utf8ToUnicode(str2, vec));
    cout << vec << endl;

    string sentence1 = "南苏丹首都朱巴发生激烈武装冲突后，来自英国、德国和瑞典的１２名维和警察在没有与联合国方面协商的情况下便擅自撤离，令联合国大为恼火，禁止他们归队继续参与维和。联合国秘书长副发言人法尔汉·哈克２１日说，这些欧洲维和警察的突然离开影响了联合国南苏丹特派团的“行动能力和成员士气”，联合国维和事务部因而决定“取消邀请”，不允许他们回到特派团，并已通知英德瑞三国。不愿公开姓名的联合国官员披露，这些擅自离岗的维和警察包括两名英国人、３名瑞典人和７名德国人，是在冲突爆发后被各自政府撤离的。\n英国常驻联合国代表团发言人马特·穆迪在一份声明中称，英国政府只是迫于当时朱巴发生的严重暴力而暂时撤出两名维和警察，“他们的安危是我们主要考虑的。这一决定已经提前跟联合国方面联络过。我们对这些警员在安全局势稳定后不被允许返回感到失望”。\n不过，一名联合国官员２０日告诉法新社记者，英德瑞三国撤离维和警察时“没有同特派团协商”。哈克当天说，这些警员“没有待在自己的岗位上”，他们被禁止返回南苏丹后，联合国也不会要求英德瑞三国派人填补留下的空缺路透社报道称，关于此事，联合国维和事务部发言人尼克·伯恩巴克甚至在一份１５日写给秘书长潘基文的“内部备忘录”中质疑英国是否还有资格担任拥有否决权的安理会常任理事国。不过，伯恩贝克稍后否认这一报道：“据我们所知，并不存在所谓‘维和事务部备忘录’。”联合国南苏丹特派团有大约１２００名维和警察和１３５万名维和军人。自本月８日以来，南苏丹总统萨尔瓦·基尔领导的部队与效忠副总统、前反政府武装领导人里克·马沙尔的部队在朱巴持续激烈交火，造成至少３００人死亡。其中，中国维和部队两人牺牲、５人负伤。基尔和马沙尔１１日晚分别命令各自部队停火。（新华社微特稿）（胡若愚）";
    vec.clear();
    ASSERT_TRUE(StringUtil::Utf8ToUnicode(sentence1, vec));
    string res = "";
    UnicodeContainerIter begin = vec.begin();
    UnicodeContainerIter end = vec.end();
    ASSERT_TRUE(StringUtil::UnicodeToUtf8(begin, end, res));
    cout << res << endl;
    ASSERT_EQ(res, sentence1);
}

TEST(TestStringUtil, UnicodeToUtf8) {
    UnicodeContainer vec;
    UnicodeContainerIter begin = vec.begin();
    UnicodeContainerIter end = vec.end();
    string res = "";
    ASSERT_TRUE(StringUtil::UnicodeToUtf8(begin, end, res));
    ASSERT_EQ(res, "");

    vec.clear();
    vec.push_back(38472);
    vec.push_back(22269);
    vec.push_back(26519);
    begin = vec.begin();
    end = vec.end();
    res = "";
    ASSERT_TRUE(StringUtil::UnicodeToUtf8(begin, end, res));
    ASSERT_EQ(res, "陈国林");
}

TEST(TestStringUtil, ToHex) {
    unsigned int value = 6;
    ASSERT_EQ(StringUtil::ToHex(value), '6');

    value = 10;
    ASSERT_EQ(StringUtil::ToHex(value), 'A');

    value = 15;
    ASSERT_EQ(StringUtil::ToHex(value), 'F');
}

TEST(TestStringUtil, FromHex) {
    char c = '6';
    ASSERT_EQ(StringUtil::FromHex(c), (unsigned int)6);

    c = 'A';
    ASSERT_EQ(StringUtil::FromHex(c), (unsigned int)10);

    c = 'F';
    ASSERT_EQ(StringUtil::FromHex(c), (unsigned int)15);
}

TEST(TestStringUtil, Quote) {
    string rawStr = "";
    ASSERT_EQ(StringUtil::Quote(rawStr), "");

    rawStr = "When using MacPorts GCC on OS X and enlisting the Clang Integrated Assembler via -Wa,-q, the assembler produces a stream of warnings for each file. A sampling of the warnings is shown below (so many of them, the Stack Overflow editor would not allow me to paste the entire stream).";
    /*When%20using%20MacPorts%20GCC%20on%20OS%20X%20and%20enlisting%20the%20Clang%20Integrated%20Assembler%20via%20-Wa,-q,%20the%20assembler%20produces%20a%20stream%20of%20warnings%20for%20each%20file.%20A%20sampling%20of%20the%20warnings%20is%20shown%20below%20%28so%20many%20of%20them,%20the%20Stack%20Overflow%20editor%20would%20not%20allow%20me%20to%20paste%20the%20entire%20stream%29.* */
    cout << StringUtil::Quote(rawStr) << endl;
}

TEST(TestStringUtil, UnQuote) {
    string quoteStr = "";
    ASSERT_EQ(StringUtil::UnQuote(quoteStr), "");

    //rawStr = "When using MacPorts GCC on OS X and enlisting the Clang Integrated Assembler via -Wa,-q, the assembler produces a stream of warnings for each file. A sampling of the warnings is shown below (so many of them, the Stack Overflow editor would not allow me to paste the entire stream).";
    quoteStr = "When%20using%20MacPorts%20GCC%20on%20OS%20X%20and%20enlisting%20the%20Clang%20Integrated%20Assembler%20via%20-Wa,-q,%20the%20assembler%20produces%20a%20stream%20of%20warnings%20for%20each%20file.%20A%20sampling%20of%20the%20warnings%20is%20shown%20below%20%28so%20many%20of%20them,%20the%20Stack%20Overflow%20editor%20would%20not%20allow%20me%20to%20paste%20the%20entire%20stream%29.";
    cout << StringUtil::UnQuote(quoteStr) << endl;
}
