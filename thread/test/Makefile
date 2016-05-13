TOP_DIR = ../
CURRENT_DIR = ./
INCLUDE_CPPS = -I$(TOP_DIR) -I$(CURRENT_DIR) -I/usr/include/mysql
LIB_DIR = -L$(CURRENT_DIR)/lib -L/lib -L/usr/lib -L.


ALL_TEST_BIN = logger_test md5_test std_extension_test string_util_test config_test argv_context_test mutex_lock_test thread_test mysql_client_test local_vector_test file_lock_test file_util_test
test: $(ALL_TEST_BIN) 
	make clean

liblogger.so: $(TOP_DIR)/logger.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(TOP_DIR)/logger.cpp
logger_test: liblogger.so logger_test.cpp 
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) logger_test.cpp -lgtest -lgtest_main -llogger -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./logger_test
libmd5.so: $(TOP_DIR)/md5.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(TOP_DIR)/md5.cpp
md5_test: libmd5.so md5_test.cpp 
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) md5_test.cpp -lgtest -lgtest_main -lmd5 -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./md5_test
std_extension_test: $(TOP_DIR)/std_extension.*
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) std_extension_test.cpp -lgtest -lgtest_main -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./std_extension_test
libstring_util.so: $(TOP_DIR)/std_extension.h $(TOP_DIR)/string_util.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(TOP_DIR)/string_util.cpp
string_util_test: libstring_util.so string_util_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) string_util_test.cpp -lgtest -lgtest_main -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./string_util_test
libconfig.so: $(TOP_DIR)/std_extension.h $(TOP_DIR)/config.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../config.cpp
config_test: liblogger.so libstring_util.so libconfig.so config_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) config_test.cpp -lgtest -lgtest_main -lconfig -llogger -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./config_test
libargv_context.so: $(TOP_DIR)/argv_context.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../argv_context.cpp
argv_context_test: libstring_util.so libargv_context.so argv_context_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) argv_context_test.cpp -lgtest -lgtest_main -largv_context -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./argv_context_test
libmutex_lock.so: $(TOP_DIR)/mutex_lock.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../mutex_lock.cpp
mutex_lock_test: libmutex_lock.so mutex_lock_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) mutex_lock_test.cpp -lgtest -lgtest_main -lmutex_lock -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mutex_lock_test
libthread.so: $(TOP_DIR)/thread.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../thread.cpp
thread_test: libthread.so thread_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) thread_test.cpp -lgtest -lgtest_main -lthread -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./thread_test
libmysql_client.so: $(TOP_DIR)/mysql_client.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../mysql_client.cpp
mysql_client_test: libmysql_client.so liblogger.so libstring_util.so mysql_client_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) mysql_client_test.cpp -lgtest -lgtest_main -lmysql_client -llogger -lstring_util -lmysqlclient -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mysql_client_test
local_vector_test: $(TOP_DIR)/local_vector.*
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) local_vector_test.cpp -lgtest -lgtest_main -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./local_vector_test
libfile_lock.so: $(TOP_DIR)/file_lock.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../file_lock.cpp
file_lock_test: libfile_lock.so file_lock_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) file_lock_test.cpp -lgtest -lgtest_main -lfile_lock -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./file_lock_test
libfile_util.so: $(TOP_DIR)/file_util.*
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../file_util.cpp
file_util_test: libstring_util.so libfile_util.so file_util_test.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) file_util_test.cpp -lgtest -lgtest_main -lfile_util -lstring_util -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./file_util_test


.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(ALL_TEST_BIN) 
