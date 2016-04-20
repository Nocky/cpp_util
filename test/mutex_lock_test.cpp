#include <include/gtest/gtest.h>
#include "include/util/mutex_lock.h"

using namespace Util;

TEST(TestMutexLock, MutexLockGuard) {
    MutexLock mutexLock;
    MutexLockGuard mutexLockGuard(mutexLock);
}
