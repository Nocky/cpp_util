#ifndef CPP_UTIL_COMMON_STDEXTENTION_H
#define CPP_UTIL_COMMON_STDEXTENTION_H

#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>

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

namespace std {

// operator << print vector all element
// empty: []
// other: [\"1\", \"2\", ...]
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    if(vec.empty()) {
        os << "[]";
        return os;
    }
    os << "[\"" << vec[0];
    size_t vecSize = vec.size();
    for(size_t i = 1; i < vecSize; i++) {
        os << "\", \"" << vec[i];
    }
    os << "\"]";
    return os;
}

// operator << print pair key-value
// key:value
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& pr) {
    os << pr.first << ":" << pr.second;
    return os;
}

// operator << print map all key-value
// empty: {}
// other: {key1:value1, key2:value2, key3:value3, ...}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& mp) {
    if(mp.empty()) {
        os << "{}";
        return os;
    }
    os << "{";
    typename map<T1, T2>::const_iterator it = mp.begin();
    os << *it; // call operator<<(ostream&, pair<T1,T2>&)
    it++;
    for (; it != mp.end(); it++) {
        os << ", " << *it;
    }
    os << "}";
    return os;
}

// operator << print unordered_map all key-value
// the same as operator<<(ostream&, map<T1,T2>&)
// empty: {}
// other: {key1:value1, key2:value2, key3:value3, ...}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const std::unordered_map<T1, T2>& ump) {
    if(ump.empty()) {
        os << "{}";
        return os;
    }
    os << "{";
    typename std::unordered_map<T1, T2>::const_iterator it = ump.begin();
    os << *it;  //call operator<<(ostream&, pair<T1,T2>&)
    it++;
    for (; it != ump.end(); it++) {
        os << ", " << *it++;
    }
    os << "}";
    return os;
}

// operator << print set all value
// empty: {}
// other: {value1, value2, value3, ...}
template<typename T>
ostream& operator<<(ostream& os, const set<T>& st) {
    if(st.empty()) {
        os << "{}";
        return os;
    }
    os << "{";
    typename set<T>::const_iterator it = st.begin();
    os << *it;
    it++;
    for (; it != st.end(); it++) {
        os << ", " << *it;
    }
    os << "}";
    return os;
}

// operator << obj to string
template<typename T>
string operator<<(string& str, const T& obj) {
    stringstream ss;
    ss << obj;
    str = ss.str();
    return str;
}

// function template
template<typename KeyType, typename ContainType>
bool IsIn(const ContainType& contain, const KeyType& key) {
    return contain.find(key) != contain.end();
}

template<typename T>
basic_string<T>& operator<<(basic_string<T>& s, ifstream& ifs) {
    return s.assign((istreambuf_iterator<T>(ifs)), istreambuf_iterator<T>());
}

template<typename T>
ofstream& operator<<(ofstream& ofs, const basic_string<T>& s) {
    ostreambuf_iterator<T> itr(ofs);
    copy(s.begin(), s.end(), itr);
    return ofs;
}

} //nemespace std
#endif //CPP_UTIL_COMMON_STDEXTENTION_H
