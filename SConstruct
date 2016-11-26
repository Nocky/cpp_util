#--- python mode ---

import os
import platform

env = Environment()

include_path = ['./cpp_util']
lib_path = []
libs = []

# platform for mac
if platform.system() == 'Darwin':
    include_path += [
        '/usr/local/include/c++/4.8.5',
        '/usr/local/include/mysql'
    ]
    lib_path += [
        '/usr/local/lib'
    ]
    libs += [
        'mysqlclient'
    ]
    env.Append(CXXFLAGS='-w -O2')
    # set special g++ version
    env.Replace(CXX='/usr/local/bin/g++-4.8')
else:
    pass

# set environment variables
env.Append(CPPPATH=Dir(include_path))
env.Append(LIBPATH=Dir(lib_path))
env.Append(LIBS=Dir(libs))

Export('env')

# build
cpps = SConscript(['cpp_util/SConscript'])  
libcpp_util = env.SharedLibrary(
    'cpp_util', cpps 
)

# clean
env.NoClean('build/lib*')

# install to build dir
env.Install('build', libcpp_util)
