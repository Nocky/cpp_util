## variable
INCLUDE_CPPS = -I../.. -I/usr/include/mysql -I../../gtest -I.
LIB_DIR = -L/lib -L/usr/lib -L../../gtest/lib -L.
ALL_TEST_BIN = mutexLockTest threadTest
ALL_DEPENDS_FILE = ../../common/*.h ../../common/*.cpp ../../thread/*.h ../../thread/*.cpp
ALL_DEPENDS_LIB = -lgtest -lgtest_main -lutil -lmysqlclient -lpthread

## unit test 
test: $(ALL_TEST_BIN) 
	make clean

libutil.so: $(ALL_DEPENDS_FILE)
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(ALL_DEPENDS_FILE)

mutexLockTest: mutexLockTest.cpp libutil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) mutexLockTest.cpp $(ALL_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mutexLockTest

threadTest: threadTest.cpp libutil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) threadTest.cpp $(ALL_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./threadTest

## clean 
.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(ALL_TEST_BIN) 
