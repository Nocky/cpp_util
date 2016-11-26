#ifndef CPP_UTIL_THREAD_NONCOPYABLE_H
#define CPP_UTIL_THREAD_NONCOPYABLE_H

#include <string>
#include <iostream>
#include "common/common.h"

NAMESPACE_SETUP(Util)
    
class NonCopyable {
protected:
    NonCopyable(){};
    virtual ~NonCopyable(){};

private:
    NonCopyable(const NonCopyable&);
    void operator=(const NonCopyable&);
}; //class NonCopyable

NAMESPACE_END(Util)
#endif //CPP_UTIL_THREAD_NONCOPYABLE_H
