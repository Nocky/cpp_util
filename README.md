## 一. C++ base util
1. c++基础库, 使用scons进行编译构建, scons兼容了Mac和Ubuntu. SConstruct根据不同的平台设置不同的编译参数，进行编译
   
   注意：Mac os下默认的编译器是Clang，编译出来的符号和g++编译不一致，所以在SConstruct里面指定了编译器为g++
2. email: cgl1079743846@gmail.com
   欢迎邮件沟通交流

### 1. Mac
```
1). build: scons -i -Q -j4 2> /dev/null
    编译会有一些没有用的Warn去不掉，直接从定向到/dev/null
2). 要求g++ 4.8，Mac系统默认为4.2在编译的时候会报找不到一些符号
3). clean: scons -c
4). 单元测试
    例如common
    scons -i -Q -j4 2> /dev/null ; scons --check=all
```

### 2. Linux
```
```

## 二.目录介绍 
### 1. cpp_util
#### 1.1 common
```
   a. common.h
   b. config.h
   c. argvContext.h
   d. localVector.h
   e. stdExtention.h
```
#### 1.2 log
```
   a. log.h
   b. loggerUtil.h
```
#### 1.3 file_util
```
   a. fileLock.h
   b. fileUtil.h
```
#### 1.4 mysql
```
   a. mysqlClient.h
```
#### 1.5 thread
```
   a. thread.h
   b. threadPool.h
   c. mutexLock.h
```
### 2. gtest
google unit test基础库
1. gtest_32 32位操作系统下编译出来的gtest和gtest_main静态库
2. gtest_64 64位操作系统下编译出来的gtest和gtest_main静态库
```
1. gtest library build
   1). git clone https://github.com/google/googletest.git googletest
   2). cd googletest/googletest
   3). mkdir build
   4). cd build
   5). cmake ..
   6). make
   7). cp libgtest* cpp_util/gtest/lib_32
       or
       cp libgtest* cpp_util/gtest/lib_64
```
