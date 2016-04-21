#ifndef CPPUTIL_CPP_UTIL_NONCOPYABLE_H
#define CPPUTIL_CPP_UTIL_NONCOPYABLE_H

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
};

} //end Util namespace
#endif //CPPUTIL_CPP_UTIL_NONCOPYABLE_H
