#ifndef CPP_UTIL_LOG_LOG_H
#define CPP_UTIL_LOG_LOG_H

#include "common/common.h"
#include "loggerUtil.h"

USING_NAMESPACE(std)
NAMESPACE_SETUP(Util)

// define log level enum value
enum LogLevel {
    LL_DEBUG = 0, 
    LL_INFO = 1, 
    LL_WARN = 2, 
    LL_ERROR = 3
};

// define get current file name
#define FILE_BASENAME \
    strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__

// define print log
#define LOG_DEBUG(fmt, ...) \
    LoggerUtil::LoggingF(LL_DEBUG, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)

#define LOG_WARN(fmt, ...) \
    LoggerUtil::LoggingF(LL_WARN, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)

#define LOG_INFO(fmt, ...) \
    LoggerUtil::LoggingF(LL_INFO, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
    LoggerUtil::LoggingF(LL_ERROR, FILE_BASENAME, __LINE__, fmt, ## __VA_ARGS__)

NAMESPACE_END(Util)
#endif //CPP_UTIL_LOG_LOG_H
