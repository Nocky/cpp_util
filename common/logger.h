#ifndef CPP_UTIL_COMMON_LOGGER_H
#define CPP_UTIL_COMMON_LOGGER_H

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

using namespace std;
namespace Util {

typedef unsigned int uint32_t;
// define log level enum value
enum LogLevel {
    LL_DEBUG = 0, 
    LL_INFO = 1, 
    LL_WARN = 2, 
    LL_ERROR = 3, 
    LL_FATAL = 4
};

// define get current file name
#define FILE_BASENAME strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__
// define print log level
#define LogDebug(fmt, ...) Logger::LoggingF(Util::LL_DEBUG, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)
#define LogInfo(fmt, ...) Logger::LoggingF(Util::LL_INFO, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)
#define LogWarn(fmt, ...) Logger::LoggingF(Util::LL_WARN, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)
#define LogError(fmt, ...) Logger::LoggingF(Util::LL_ERROR, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)
#define LogFatal(fmt, ...) Logger::LoggingF(Util::LL_FATAL, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)

// class Logger
class Logger {
public:
    Logger();
    virtual ~Logger();

private:
    Logger(const Logger& obj);
    void operator=(const Logger& obj);

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
}; //class Logger

} //namespace Util
#endif //CPP_UTIL_COMMON_LOGGER_H
