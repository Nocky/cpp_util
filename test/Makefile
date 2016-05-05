# include dir
ROOT_DIR = ../
CURRENT_DIR = ./
SRC_FILE_INCLUDE_DIR = -I$(ROOT_DIR) -I$(CURRENT_DIR) -I/usr/include/mysql

# lib dir
LIB_DIR = -L$(CURRENT_DIR)/lib -L/lib -L/usr/lib -L.

# all test binary
ALL_TEST_BIN = logger_test md5_test std_extension_test string_util_test config_test argv_context_test mutex_lock_test thread_test mysql_client_test local_vector_test file_lock_test file_util_test

# 1. cmd: make check
# 2. do run all unit test
test: $(ALL_TEST_BIN) 
	make clean

# 1. cmd: make logger_test
# 2. do run logger unit test case
liblogger.so: ../logger.h ../logger.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../logger.cpp
	
logger_test: liblogger.so logger_test.cpp 
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) logger_test.cpp -lgtest -lgtest_main -llogger -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./logger_test


# 1. cmd: make md5_test 
# 2. do run md5 unit test case
libmd5.so: ../md5.h ../md5.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../md5.cpp
	
md5_test: libmd5.so md5_test.cpp 
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) md5_test.cpp -lgtest -lgtest_main -lmd5 -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./md5_test


# 1. cmd: make std_extension_test 
# 2. do run std_extension unit test case
std_extension_test: ../std_extension.h std_extension_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) std_extension_test.cpp -lgtest -lgtest_main -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./std_extension_test


# 1. cmd: make string_util_test 
# 2. do run string_util unit test case
libstring_util.so: ../std_extension.h ../string_util.h ../string_util.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../string_util.cpp

string_util_test: libstring_util.so string_util_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) string_util_test.cpp -lgtest -lgtest_main -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./string_util_test


# 1. cmd: make config_test 
# 2. do run config_test unit test case
libconfig.so: ../logger.h ../logger.cpp ../string_util.h ../string_util.cpp ../std_extension.h ../config.h ../config.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../config.cpp

config_test: liblogger.so libstring_util.so libconfig.so config_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) config_test.cpp -lgtest -lgtest_main -lconfig -llogger -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./config_test


# 1. cmd: make argv_context_test 
# 2. do run argv_context_test unit test case
libargv_context.so: ../string_util.h ../string_util.cpp ../argv_context.h ../argv_context.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../argv_context.cpp

argv_context_test: libstring_util.so libargv_context.so argv_context_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) argv_context_test.cpp -lgtest -lgtest_main -largv_context -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./argv_context_test

# 1. cmd: make mutex_lock_test 
# 2. do run mutex_lock_test unit test case
libmutex_lock.so: ../logger.h ../logger.cpp ../non_copyable.h ../mutex_lock.h ../mutex_lock.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../mutex_lock.cpp

mutex_lock_test: libmutex_lock.so mutex_lock_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) mutex_lock_test.cpp -lgtest -lgtest_main -lmutex_lock -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mutex_lock_test


# 1. cmd: make thread_test
# 2. do run thread_test unit test case
libthread.so: ../non_copyable.h ../thread.h ../thread.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../thread.cpp

thread_test: libthread.so thread_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) thread_test.cpp -lgtest -lgtest_main -lthread -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./thread_test


# 1. cmd: make mysql_client_test
# 2. do run mysql_client_test unit test case
libmysql_client.so: ../logger.h ../logger.cpp ../string_util.h ../string_util.cpp ../mysql_client.h ../mysql_client.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../mysql_client.cpp

mysql_client_test: libmysql_client.so liblogger.so libstring_util.so mysql_client_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) mysql_client_test.cpp -lgtest -lgtest_main -lmysql_client -llogger -lstring_util -lmysqlclient -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mysql_client_test

# 1. cmd: make local_vector_test 
# 2. do run local_vector_test unit test case
local_vector_test: ../local_vector.h local_vector_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) local_vector_test.cpp -lgtest -lgtest_main -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./local_vector_test

# 1. cmd: make file_lock_test 
# 2. do run file_lock_test unit test case
libfile_lock.so: ../file_lock.h ../file_lock.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../file_lock.cpp

file_lock_test: libfile_lock.so file_lock_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) file_lock_test.cpp -lgtest -lgtest_main -lfile_lock -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./file_lock_test
	

# 1. cmd: make file_util_test 
# 2. do run file_util_test unit test case
libfile_util.so: ../file_util.h ../file_util.cpp ../string_util.h ../string_util.cpp
	g++ -o $@ -fPIC -shared $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) ../file_util.cpp ../string_util.cpp

file_util_test: libfile_util.so file_util_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(SRC_FILE_INCLUDE_DIR) $(LIB_DIR) file_util_test.cpp -lgtest -lgtest_main -lfile_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./file_util_test

# 1. cmd: make clean 
# 2. do clear all .so or .a or .o and other binary file 
.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(ALL_TEST_BIN) 
