import os
import platform

env = Environment()

include_path = ['.']
if platform.system() == 'Darwin':
    cpp_dir = '/usr/include/c++/' + os.listdir('/usr/include/c++')[0]
    mysql_dir = '/usr/local/include/mysql'
    include_path.append(cpp_dir)
    include_path.append(mysql_dir)
env.Append(CPPPATH=Dir(include_path))
env['STATIC_AND_SHARED_OBJECTS_ARE_THE_SAME']=1

Export('env')

sub_obj = SConscript([
    'cpp_util/SConscript'
    ])  
