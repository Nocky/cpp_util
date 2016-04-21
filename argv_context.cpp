#include <assert.h>
#include "argv_context.h"

using namespace std;

namespace Util {

ArgvContext::ArgvContext(const int argc, const char* const argv[]) {
    assert(argc > 0);
    assert(argv != NULL);
    for(int i = 0; i < argc; i++) {
        // options, for example 
        // 1. -name chenguolin
        // 2. --name chenguolin
        if(StringUtil::StartsWith(argv[i], "-")) {
            if((i + 1 < argc) && !StringUtil::StartsWith(argv[i+1], "-")) {
                mOptionsMap[argv[i]] = argv[i+1];
                i++;
            }
            else {
                mOptionsSet.insert(argv[i]);
            }
        }
        else {
            mArgsVec.push_back(argv[i]);
        }
    }
}

ArgvContext::~ArgvContext() {
}

bool ArgvContext::HasOption(const string& key) const{
    if (mOptionsMap.find(key) != mOptionsMap.end() 
            || mOptionsSet.find(key) != mOptionsSet.end()) {
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
    os << argvContext.mArgsVec;
    os << argvContext.mOptionsMap;
    os << argvContext.mOptionsSet;
    return os;
}

} //end namespace Util
