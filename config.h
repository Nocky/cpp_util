#ifndef SIMHASH_SERVER_INCLUDE_UTIL_CONFIG_H
#define SIMHASH_SERVER_INCLUDE_UTIL_CONFIG_H

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include "include/util/std_extention.h"

using namespace std;

namespace Util {

class Config {
public:
    Config(const string& filePath);
    virtual ~Config();

private:
    Config(const Config&);
    void operator=(const Config&);

public:
    /*
     * 1. load file to config
     * 2. file text format: key=value
     * */
    void LoadFile();
    bool HasKey(const string& key) const;
    bool GetValue(const string& key, string& value) const;
    bool GetValue(const string& key, int& value) const;
    const char* operator[](const char* key) const;
    string GetConfigInfo() const;

private:
    string mFilePath;
    map<string, string> mMap;
};

} //end namespace Util
#endif //SIMHASH_SERVER_INCLUDE_UTIL_CONFIG_H
