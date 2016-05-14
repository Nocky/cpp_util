INCLUDE_CPPS = -I. -I/usr/include/mysql
LIB_DIR = -L/lib -L/usr/lib -L.
ALL_DEPENDS_FILE = common/*.h common/*.cpp thread/*.h thread/*.cpp
ALL_DEPENDS_LIB = -lutil -lmysqlclient -lpthread

build: $(ALL_TEST_BIN) 
	g++ -o libutil.so -fPIC -shared $(INCLUDE_CPPS) $(LIB_DIR) $(ALL_DEPENDS_FILE)

.PHONY : clean
clean: 
	-rm -f *.o *.a *.so
	-rm -f $(ALL_TEST_BIN) 
