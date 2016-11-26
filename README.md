# C++ base util
c++基础库, 使用scons进行编译构建, scons兼容了Mac和Ubuntu
SConstruct根据不同的平台设置不同的编译参数，进行编译

1. Mac
```
1). build: scons -i -Q -j4 2> /dev/null
    编译会有一些没有用的Warn去不掉，直接从定向到/dev/null
2). 要求g++ 4.8，Mac系统默认为4.2在编译的时候会报找不到一些符号
```

2. Linux
```
```

## 一.简介
1. c++ 基础库
2. email: cgl1079743846@gmail.com

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
