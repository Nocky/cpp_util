#ifndef CPP_UTIL_COMMON_CONFIG_H
#define CPP_UTIL_COMMON_CONFIG_H

#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include "std_extension/std_extension.h"

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

} //namespace Util
#endif //CPP_UTIL_COMMON_CONFIG_H
