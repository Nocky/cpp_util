#include <gtest/gtest.h>
#include "mutex_lock.h"

using namespace Util;

TEST(TestMutexLock, MutexLockGuard) {
    MutexLock mutexLock;
    MutexLockGuard mutexLockGuard(mutexLock);
}
