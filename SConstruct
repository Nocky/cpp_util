#--- python mode ---

import os
import platform

env = Environment()
env['project'] = 'cpp_util'
env['version'] = '0.0.2'
env['release'] = 'rc_1'

include_path = ['./cpp_util']
lib_path = []
libs = ['pthread']

# platform for mac
if platform.system() == 'Darwin':
    include_path += [
        '/usr/local/include/mysql'
    ]
    lib_path += [
        '/usr/local/lib'
    ]
    libs += [
        'mysqlclient'
    ]
    # set special g++ version
    env.Replace(CXX='/usr/local/bin/g++-4.8')
else:
    include_path += [
        '/usr/include/mysql'
    ]
    libs += [
        'mysqlclient'
    ]

# set environment variables
env.Append(CPPPATH=Dir(include_path))
env.Append(LIBPATH=Dir(lib_path))
env.Append(LIBS=Dir(libs))
env.Append(CXXFLAGS='-Wall -g -O2 -fPIC -DLOGGER_LEVEL=LL_INFO')

Export('env')

# build
cpps = SConscript([
    'cpp_util/SConscript'
])  
libcpp_util = env.SharedLibrary(
    'cpp_util', cpps 
)

# install to build dir
env.Install('build', libcpp_util)
