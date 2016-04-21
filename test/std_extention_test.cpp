#include <gtest/gtest.h>
#include "std_extention.h"

using namespace std;

TEST(TestStdExtention, operatorOutVector){
    // vector empty
    vector<int> vec1;
    cout << "Start to cout empty vector ..." << endl;
    cout << vec1 << endl;
    cout << "Success to cout empty vector" << endl;

    // vector non empty
    vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    cout << "Start to cout non empty vector ..." << endl;
    cout << vec2 << endl;
    cout << "Success to cout non empty vector" << endl;
}

TEST(TestStdExtention, operatorOutPair){
    pair<int, int> pr(1,2);
    cout << "Start to cout pair ..." << endl;
    cout << pr << endl;
    cout << "Success to cout pair" << endl;
}

TEST(TestStdExtention, operatorOutMap){
    // map empty
    map<string, int> mp1;
    cout << "Start to cout empty map ..." << endl;
    cout << mp1 << endl;
    cout << "Success to cout empty map" << endl;

    // map non empty
    map<string, int> mp2;
    mp2.insert(make_pair<string, int>("one", 1));
    mp2.insert(make_pair<string, int>("two", 2));
    cout << "Start to cout non empty map ..." << endl;
    cout << mp2 << endl;
    cout << "Success to cout non empty map" << endl;
}

TEST(TestStdExtention, operatorOutUnorderedMap){
    // unordered_map empty
    unordered_map<string, int> mp1;
    cout << "Start to cout empty unordered_map ..." << endl;
    cout << mp1 << endl;
    cout << "Success to cout empty unordered_map" << endl;

    // unordered_map non empty
    map<string, int> mp2;
    mp2.insert(make_pair<string, int>("one", 1));
    mp2.insert(make_pair<string, int>("two", 2));
    cout << "Start to cout non empty unordered_map ..." << endl;
    cout << mp2 << endl;
    cout << "Success to cout non empty unordered_map" << endl;
}

TEST(TestStdExtention, operatorOutSet){
    // set empty
    set<int> s1;
    cout << "Start to cout empty set ..." << endl;
    cout << s1 << endl;
    cout << "Success to cout empty set" << endl;

    // map non empty
    set<int> s2;
    s2.insert(1);
    s2.insert(2);
    cout << "Start to cout non empty set ..." << endl;
    cout << s2 << endl;
    cout << "Success to cout non empty set" << endl;
}

TEST(TestStdExtention, operatorOutObjToString){
    // output vector to string
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    string vecString = "";
    operator<<(vecString, vec);
    ASSERT_EQ(vecString, "[\"1\", \"2\"]");

    // output map to string
    map<string, int> mp;
    mp.insert(make_pair<string, int>("one", 1));
    string mpString = "";
    operator<<(mpString, mp);
    ASSERT_EQ(mpString, "{one:1}");
}

TEST(TestStdExtention, IsIn){
    map<string, int> mp;
    mp.insert(make_pair<string, int>("one", 1));
    ASSERT_TRUE(IsIn(mp, "one"));
    ASSERT_FALSE(IsIn(mp, "two"));
}
