INCLUDE_CPPS = -I. -I/usr/include/mysql
LIB_DIR = -L/lib -L/usr/lib -L.
UTIL_DEPENDS_FILE = common/*.h common/*.cpp thread/*.h thread/*.cpp
UTIL_DEPENDS_LIB = -lmysqlclient

build: $(ALL_DEPENDS_FILE) 
	g++ -o libcpputil.so -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(UTIL_DEPENDS_FILE) $(UTIL_DEPENDS_LIB)

.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
