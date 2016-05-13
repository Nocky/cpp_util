#ifndef CPP_UTIL_THREAD_NONCOPYABLE_H
#define CPP_UTIL_THREAD_NONCOPYABLE_H

#include <string>
#include <iostream>

namespace Util {
    
class NonCopyable {
protected:
    NonCopyable(){};
    virtual ~NonCopyable(){};

private:
    NonCopyable(const NonCopyable&);
    void operator=(const NonCopyable&);
}; //class NonCopyable

} //namespace Util
#endif //CPP_UTIL_THREAD_NONCOPYABLE_H
