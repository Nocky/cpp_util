#include <gtest/gtest.h>
#include "log.h"

using namespace Util;

TEST(TestPrintLog, testDebug){
	LOG_DEBUG("this is print debug log");
}

TEST(TestPrintLog, testInfo){
	LOG_INFO("this is print info log");
}

TEST(TestPrintLog, testWarn){
	LOG_WARN("this is print warn log");
}

TEST(TestPrintLog, testError){
	LOG_ERROR("this is print error log");
}
