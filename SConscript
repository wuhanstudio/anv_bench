from building import *
import rtconfig

# get current directory
cwd     = GetCurrentDir()

# The set of source files associated with this SConscript file.

src = []

if GetDepend('ANV_BENCH_USING_EXAMPLE'):
	src    += Glob('anv_bench_example.c')

if GetDepend('ANV_BENCH_USING_GROUP_EXAMPLE'):
	src    += Glob('anv_bench_group_example.c')

LOCAL_CCFLAGS = ''
path   =  [cwd]

group = DefineGroup('anv_bench', src, CPPPATH = path, depend = ['PKG_USING_ANV_BENCH'], LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
