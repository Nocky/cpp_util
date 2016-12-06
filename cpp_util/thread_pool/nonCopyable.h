#ifndef CPP_UTIL_THREAD_POOL_NONCOPYABLE_H
#define CPP_UTIL_THREAD_POOL_NONCOPYABLE_H

#include <string>
#include <iostream>
#include "common/common.h"

NAMESPACE_SETUP(Util)
    
class NonCopyable {
public:
    NonCopyable(){}
    virtual ~NonCopyable(){}

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
}; //class NonCopyable

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_POOL_NONCOPYABLE_H
