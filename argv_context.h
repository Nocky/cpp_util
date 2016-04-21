#ifndef CPPUTIL_CPP_UTIL_ARGVCONTENTEXT_H
#define CPPUTIL_CPP_UTIL_ARGVCONTENTEXT_H

#include <set>
#include <map>
#include <sstream>
#include "string_util.h"

using namespace std;
namespace Util {

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
    vector<string> mArgsVec;
    map<string, string> mOptionsMap;
    set<string> mOptionsSet; 
};

} //end namespace Util
#endif //CPPUTIL_CPP_UTIL_ARGVCONTENTEXT_H
