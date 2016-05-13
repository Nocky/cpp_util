#include <assert.h>
#include "common/stringUtil.h"
#include "common/argvContext.h"

using namespace std;
namespace Util {

ArgvContext::ArgvContext(const int argc, const char* const argv[]) {
    assert(argc > 0);
    assert(argv != NULL);
    for(int i = 0; i < argc; i++) {
        // options, for example 
        // 1. chenguolin 
        // 2. -name chenguolin
        // 3. --name chenguolin
        if(StringUtil::StartsWith(argv[i], "-")) {
            string option = string(argv[i]);
            option = StringUtil::Trim(option, '-');
            string argument = "";
            if((i+1 < argc) && !StringUtil::StartsWith(argv[i+1], "-")) {
                argument = string(argv[++i]);
            }
            mOptionsMap[option] = argument;
        }
        else {
            mArgsVec.push_back(string(argv[i]));
        }
    }
}

ArgvContext::~ArgvContext() {
}

bool ArgvContext::HasOption(const string& key) const{
    if (mOptionsMap.find(key) != mOptionsMap.end()) {
        return true;
    }
    return false;
}

string ArgvContext::operator[](size_t index) const {
    assert(index < mArgsVec.size());
    return mArgsVec[index];
} 

string ArgvContext::operator[](const string& key) const{
    map<string, string>::const_iterator it;
    it = mOptionsMap.find(key);
    if (it != mOptionsMap.end()) {
        return it->second;
    }
    return "";
}

ostream& operator<<(ostream& os, const ArgvContext& argvContext) {
    os << argvContext.mOptionsMap;
    os << argvContext.mArgsVec;
    return os;
}

} //namespace Util
