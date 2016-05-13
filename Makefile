INCLUDE_CPPS = -I../.. -I/usr/include/mysql
LIB_DIR = -L../../gtest/lib -L/lib -L/usr/lib -L.

ALL_TEST_BIN = argvContextTest
test: $(ALL_TEST_BIN) 
	make clean

argvContextTest:  ../argvContext.* ../../string_util/stringUtil.*  argvContextTest.cpp
	g++ -o libargvContext.so -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) ../argvContext.cpp ../../string_util/stringUtil.cpp
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) argvContextTest.cpp -lgtest -lgtest_main -largvContext -lpthread
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./argvContextTest

.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(ALL_TEST_BIN) 
