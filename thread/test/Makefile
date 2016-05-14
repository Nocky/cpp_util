## variable
INCLUDE_CPPS = -I../.. -I/usr/include/mysql -I../../gtest -I.
LIB_DIR = -L/lib -L/usr/lib -L../../gtest/lib -L.
ALL_DEPENDS_FILE = ../../common/*.h ../../common/*.cpp ../../thread/*.h ../../thread/*.cpp
UTIL_DEPENDS_LIB = -lmysqlclient
TEST_BIN_DEPENDS_LIB = -lgtest -lgtest_main -lcpputil -lpthread
TEST_BIN = mutexLockTest threadTest

## unit test 
test: $(TEST_BIN) 
	make clean

libcpputil.so: $(ALL_DEPENDS_FILE)
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(ALL_DEPENDS_FILE) $(UTIL_DEPENDS_LIB)

mutexLockTest: mutexLockTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) mutexLockTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mutexLockTest

threadTest: threadTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) threadTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./threadTest

## clean 
.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(TEST_BIN) 
