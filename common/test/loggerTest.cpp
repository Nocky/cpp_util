#include <gtest/gtest.h>
#include "common/logger.h"

using namespace Util;

TEST(TestPrintLog, testDebug){
	LogDebug("this is print debug log");
}

TEST(TestPrintLog, testInfo){
	LogInfo("this is print info log");
}

TEST(TestPrintLog, testWarn){
	LogWarn("this is print warn log");
}

TEST(TestPrintLog, testError){
	LogError("this is print error log");
}

TEST(TestPrintLog, testFatal){
	LogFatal("this is print fatal log");
}
