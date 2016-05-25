## variable
INCLUDE_CPPS = -I../../ -I../../common -I../../gtest -I/usr/include/mysql -I.
LIB_DIR = -L/lib -L/usr/lib -L../../gtest/lib -L.
ALL_DEPENDS_FILE = ../../common/*.h ../../common/*.cpp ../../thread/*.h ../../thread/*.cpp
UTIL_DEPENDS_LIB = -lmysqlclient
TEST_BIN_DEPENDS_LIB = -lgtest -lgtest_main -lcpputil -lpthread
TEST_BIN = loggerTest md5Test stdExtensionTest stringUtilTest configTest argvContextTest mysqlClientTest localVectorTest fileLockTest fileUtilTest

## unit test 
test: $(TEST_BIN) 
	make clean

libcpputil.so: $(ALL_DEPENDS_FILE)
	g++ -o $@ -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(ALL_DEPENDS_FILE) $(UTIL_DEPENDS_LIB)

loggerTest: loggerTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) loggerTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./loggerTest

md5Test: md5Test.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) md5Test.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./md5Test

stdExtensionTest: stdExtensionTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) stdExtensionTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./stdExtensionTest

stringUtilTest: stringUtilTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) stringUtilTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./stringUtilTest

configTest: configTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) configTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./configTest

argvContextTest: argvContextTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) argvContextTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./argvContextTest

mysqlClientTest: mysqlClientTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) mysqlClientTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./mysqlClientTest

localVectorTest: localVectorTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) localVectorTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./localVectorTest

fileLockTest: fileLockTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) fileLockTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./fileLockTest

fileUtilTest: fileUtilTest.cpp libcpputil.so
	g++ -o $@ -O3 -DLOGGER_LEVEL=LL_INFO -Wall -g $(INCLUDE_CPPS) $(LIB_DIR) fileUtilTest.cpp $(TEST_BIN_DEPENDS_LIB)
	LD_LIBRARY_PATH=$LD_LIBRARY_PATH:. ./fileUtilTest


## clean
.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(TEST_BIN) 
