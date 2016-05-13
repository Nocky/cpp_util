#include "common/logger.h"

using namespace std;
namespace Util {

// init static var
const char* Logger::LOG_FORMAT = "[%s] [%s] [%s:%d] [%s]\n";
const char* Logger::LOG_TIME_FORMAT = "%Y-%m-%d %H:%M:%S";
const uint32_t Logger::LEVEL_ARRAY_SIZE = 5;
const uint32_t Logger::TIME_STR_BUFFER_SIZE = 32;
const char* Logger::LOG_LEVEL_ARRAY[]= {
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "FATAL"
};

Logger::Logger() {
}

Logger::~Logger() {
}

void Logger::Logging(size_t level, const std::string& msg, const char* fileName, int lineNo) {
	assert(level <= LL_FATAL);
	char buf[TIME_STR_BUFFER_SIZE];
	time_t timeNow;
	time(&timeNow);
	strftime(buf, sizeof(buf), LOG_TIME_FORMAT, localtime(&timeNow));
	// print log to console stderr
	fprintf(stderr, LOG_FORMAT, LOG_LEVEL_ARRAY[level], buf, fileName, lineNo, msg.c_str());
}

void Logger::LoggingF(size_t level, const char* fileName, int lineNo, const char* const fmt, ...) {
	assert(level <= LL_FATAL);
	int size = 256;
	std::string msg;
	va_list ap;
	while (1) {
		msg.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char *)msg.c_str(), size, fmt, ap);
		va_end(ap);
		if (n > -1 && n < size) {
			msg.resize(n);
			break;
		}
		// else extend size
		size *= 2;
	}
	Logging(level, msg, fileName, lineNo);
}

} //namespace Util
