#include "common/logger.h"
#include "common/config.h"
#include "common/stringUtil.h"

using namespace std;
namespace Util {

Config::Config(const string& filePath) {
    assert(filePath != "");
    mFilePath = filePath;
}

Config::~Config() {
}

void Config::LoadFile() {
    ifstream ifs(mFilePath.c_str()); 
    assert(ifs);
    string line = "";
    size_t lineNo = 0;
    while (getline(ifs, line)) {
        lineNo++; 
        StringUtil::Trim(line);
        if (line == "" || StringUtil::StartsWith(line, "#")) {
            continue;
        }
        vector<string> vecBuf;
        if (!StringUtil::Split(line, vecBuf, "=") || vecBuf.size() != 2) {
           LogError("Line number:[%d] line:[%s] is illegal.", lineNo, line.c_str()); 
           mMap.clear();
           return;
        }
        string key = vecBuf[0];
        string value = vecBuf[1];
        StringUtil::Trim(key);
        StringUtil::Trim(value);
        mMap.insert(make_pair<string, string>(key, value)); 
    }
}

bool Config::HasKey(const string& key) const{
    return mMap.find(key) != mMap.end();
} 

bool Config::GetValue(const string& key, string& value) const{
    if (!HasKey(key)) {
        return false;
    }
    map<string, string>::const_iterator it = mMap.find(key);
    value = it->second;
    return true;
}

bool Config::GetValue(const string& key, int& value) const{
    string v = "";
    if (!GetValue(key, v)) {
        return false;
    }
    value = atoi(v.c_str());
    return true;
}

const char* Config::operator[](const char* key) const{
    string value = "";
    if (NULL == key || !HasKey(string(key)) || !GetValue(string(key), value)) {
        return NULL;
    }
    return value.c_str(); 
}

string Config::GetConfigInfo() const {
    string configInfo = "";
    return operator<<(configInfo, mMap);  
}

} //namespace Util
