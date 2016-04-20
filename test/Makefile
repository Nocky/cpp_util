# include dir
ROOT_DIR = ../../..
CURRENT_DIR = ./
SRC_FILE_INCLUDE_DIR = -I$(ROOT_DIR) -I$(ROOT_DIR)/include

# lib dir
LIB_DIR = -L$(ROOT_DIR)/lib -L/lib -L/usr/lib -L.

# all test binary
ALL_TEST_BIN = logger_test md5_test std_extention_test string_util_test config_test argv_context_test mutex_lock_test thread_test

# 1. cmd: make check
# 2. do run all unit test
check: $(ALL_TEST_BIN) 
	make clean

# 1. cmd: make logger_test
# 2. do run logger unit test case
liblogger.so: ../logger.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) $<
	
logger_test: liblogger.so logger_test.cpp 
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) logger_test.cpp -lgtest -lgtest_main -llogger -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./logger_test


# 1. cmd: make md5_test 
# 2. do run md5 unit test case
libmd5.so: ../md5.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) $<
	
md5_test: libmd5.so md5_test.cpp 
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) md5_test.cpp -lgtest -lgtest_main -lmd5 -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./md5_test


# 1. cmd: make std_extention_test 
# 2. do run std_extention unit test case
std_extention_test: ../std_extention.h std_extention_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) std_extention_test.cpp -lgtest -lgtest_main -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./std_extention_test


# 1. cmd: make string_util_test 
# 2. do run string_util unit test case
libstring_util.so: ../code_converter.cpp ../string_util.h ../string_util.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../code_converter.cpp ../string_util.cpp
string_util_test: libstring_util.so string_util_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) string_util_test.cpp -lgtest -lgtest_main -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./string_util_test


# 1. cmd: make config_test 
# 2. do run config_test unit test case
libconfig.so: ../config.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../config.cpp

config_test: liblogger.so libstring_util.so libconfig.so config_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) config_test.cpp -lgtest -lgtest_main -lconfig -llogger -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./config_test

# 1. cmd: make argv_context_test 
# 2. do run argv_context_test unit test case
libargv_context.so: ../string_util.h ../string_util.cpp ../argv_context.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../argv_context.cpp

argv_context_test: libstring_util.so libargv_context.so argv_context_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) argv_context_test.cpp -lgtest -lgtest_main -largv_context -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./argv_context_test

# 1. cmd: make mutex_lock_test 
# 2. do run mutex_lock_test unit test case
libmutex_lock.so: ../mutex_lock.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../mutex_lock.cpp

mutex_lock_test: libmutex_lock.so mutex_lock_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) mutex_lock_test.cpp -lgtest -lgtest_main -lmutex_lock -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mutex_lock_test

# 1. cmd: make thread_test
# 2. do run thread_test unit test case
libthread.so: ../thread.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../thread.cpp

thread_test: libthread.so thread_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) thread_test.cpp -lgtest -lgtest_main -lthread -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./thread_test

# 1. cmd: make clean 
# 2. do clear all .so or .a or .o and other binary file 
.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(ALL_TEST_BIN) 
