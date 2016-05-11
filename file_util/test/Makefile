## variable
TOP_DIR = ../../
CURRENT_DIR = ./
INCLUDE_CPPS = -I$(TOP_DIR) -I$(CURRENT_DIR)
LIB_DIR = -L/lib -L/usr/lib -L.


## unit test
ALL_TEST_BIN = file_lock_test file_util_test
test: $(ALL_TEST_BIN) 
	make clean

libcpp_util.so: $(TOP_DIR)/common/.* $(TOP_DIR)/file_util/.* $(TOP_DIR)/std_extension/.* $(TOP_DIR)/string_util/.* 
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
