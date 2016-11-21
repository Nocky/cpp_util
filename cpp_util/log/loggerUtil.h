#ifndef CPP_UTIL_LOG_LOGGERUTIL_H
#define CPP_UTIL_LOG_LOGGERUTIL_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "cpp_util/common/common.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

typedef unsigned int uint32_t;

// class LoggerUtil
class LoggerUtil {
public:
    LoggerUtil();
    virtual ~LoggerUtil();

private:
    LoggerUtil(const LoggerUtil& obj);
    void operator=(const LoggerUtil& obj);

public:
    static void Logging(size_t level, const std::string& msg, const char* fileName, int lineNo);
    static void LoggingF(size_t level, const char* fileName, int lineNo, const char* const fmt, ...);

private:
    // [INFO 2016-03-20 22:19:34 simhash_server.cpp:45 ...]  
    static const char* LOG_FORMAT;
    static const char* LOG_TIME_FORMAT;
    static const uint32_t LEVEL_ARRAY_SIZE;
    static const uint32_t TIME_STR_BUFFER_SIZE;
    static const char* LOG_LEVEL_ARRAY[];
}; //class LoggerUtil

NAMESPACE_END(Util)
#endif //CPP_UTIL_LOG_LOGGERUTIL_H
