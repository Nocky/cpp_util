#include <gtest/gtest.h>
#include "local_vector.h"

using namespace std;
using namespace Util;

TEST(TestLocalVector, Construct1) {
    LocalVector<int> vec;
}

TEST(TestLocalVector, Construct2) {
    LocalVector<int> vec;
    LocalVector<int> vec2(vec);
}

TEST(TestLocalVector, Construct3) {
    LocalVector<int> vec;
    const int* begin = vec.begin();
    const int* end = vec.end();
    LocalVector<int> vec2(begin, end);
}

TEST(TestLocalVector, Construct4) {
    size_t size = 2;
    int value = 100;
    LocalVector<int> vec(size, value);
}

TEST(TestLocalVector, PushBack) {
    size_t size = 2;
    int value = 100;
    LocalVector<int> vec(size, value);
    ASSERT_EQ(vec[0], 100);
    ASSERT_EQ(vec[1], 100);

    vec.push_back(300);
    ASSERT_EQ(vec[2], 300);
}

TEST(TestLocalVector, Resize) {
    size_t size = 2;
    int value = 100;
    LocalVector<int> vec(size, value);
    ASSERT_EQ(vec[0], 100);
    ASSERT_EQ(vec[1], 100);

    ASSERT_EQ((size_t)2, vec.size());
    ASSERT_EQ((size_t)16, vec.capacity());
    vec.resize(16);
    ASSERT_EQ((size_t)2, vec.size());
    ASSERT_EQ((size_t)16, vec.capacity());

    ASSERT_EQ((size_t)2, vec.size());
    ASSERT_EQ((size_t)16, vec.capacity());
    vec.resize(32);
    ASSERT_EQ((size_t)2, vec.size());
    ASSERT_EQ((size_t)32, vec.capacity());
}

TEST(TestLocalVector, Empty) {
    LocalVector<int> vec;
    ASSERT_TRUE(vec.empty());
}

TEST(TestLocalVector, Begin) {
    size_t size = 2;
    int value = 100;
    LocalVector<int> vec(size, value);
    const LocalVector<int> vec2 = vec;
    const int* begin1 = vec2.begin();
    const int* end1 = vec2.end();
    ASSERT_EQ(*begin1, 100);
    ASSERT_EQ(*(end1-1), 100);

    LocalVector<int> vec3 = vec;
    int* begin2 = vec3.begin();
    int* end2 = vec3.end();
    ASSERT_EQ(*begin2, 100);
    ASSERT_EQ(*(end2-1), 100);
}

TEST(TestLocalVector, Clear) {
    size_t size = 32;
    int value = 100;
    LocalVector<int> vec(size, value);
    ASSERT_EQ((size_t)32, vec.size());
    ASSERT_EQ((size_t)32, vec.capacity());
    vec.clear();
    ASSERT_EQ((size_t)0, vec.size());
    ASSERT_EQ((size_t)16, vec.capacity());
}

