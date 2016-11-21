#ifndef CPP_UTIL_COMMON_ARGVCONTEXT_H
#define CPP_UTIL_COMMON_ARGVCONTEXT_H

#include <map>
#include <vector>
#include <sstream>
#include <tr1/memory>
#include "common.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

class ArgvContext {
public :
    ArgvContext(const int argc, const char* const argv[]);
    virtual ~ArgvContext();

public:            
    /*
     * 1. judge has option key
     * 2. return true/false
     * */
    bool HasOption(const string& key) const;

    /*
     * 1. operator [], return index argument
     * */
    string operator[](size_t index) const;

    /*
     * 1. operator [], return key optiona value 
     * */
    string operator[](const string& key) const;

public:
    /*
     * 1. friend function
     * 2. print all arguments and all options
     * */
    friend ostream& operator<<(ostream& os, const ArgvContext& argvContext); 

private:
    map<string, string> mOptionsMap;
    vector<string> mArgsVec; 
}; //class ArgvContext
typedef std::tr1::shared_ptr<ArgvContext> ArgvContextPtr;

NAMESPACE_END(Util)
#endif //CPP_UTIL_COMMON_ARGVCONTEXT_H
