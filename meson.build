project('rvemitter', 'cpp', default_options : ['cpp_std=c++17'])

cxx = 'clang' #meson.get_compiler('cpp')
fmt = declare_dependency(
    link_args : ['-lfmt'])

core = declare_dependency(
  link_args: ['-lpthread', '-lz'],
  sources: ['core/src/regalloc/arch/rv32/rv32e_regalloc.cpp'],
  include_directories : include_directories( ['.', 'core/'] )
)

test = declare_dependency(
  link_args: ['-lpthread', '-lz'],
  sources: ['test/main.cpp', 'test/simple/simple.cpp'],
  include_directories : include_directories( ['.', 'core/'] )
)
 
executable('rvemitter', dependencies: [core, fmt, test])
