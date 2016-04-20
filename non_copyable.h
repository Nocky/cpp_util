#ifndef SIMHASH_SERVER_INCLUDE_UTIL_NONCOPYABLE_H
#define SIMHASH_SERVER_INCLUDE_UTIL_NONCOPYABLE_H

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
#endif //SIMHASH_SERVER_INCLUDE_UTIL_NONCOPYABLE_H
