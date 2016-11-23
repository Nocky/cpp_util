#ifndef CPP_UTIL_COMMON_COMMON_H
#define CPP_UTIL_COMMON_COMMON_H

#include <set>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

// unordered_map and unordered_set has stdandard in c++ version 11
#if(__cplusplus == 201103L)
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
namespace std {
    using std::tr1::unordered_map;
    using std::tr1::unordered_set;
}
#endif

#define NAMESPACE_SETUP(n) \
    namespace n {

#define NAMESPACE_END(n) \
    }

#define USING_NAMESPACE(n) \
    using namespace n;

typedef std::unordered_set<std::string> StrSet;
typedef std::unordered_map<std::string, std::string> Str2StrMap;

#endif //CPP_UTIL_COMMON_COMMON_H
