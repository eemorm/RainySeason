project('RainySeason', 'cpp',
  version : '0.01',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

if host_machine.system() == 'windows'
  sfml_graphics = cpp.find_library('sfml-graphics', dirs : 'lib')
  sfml_window = cpp.find_library('sfml-window', dirs : 'lib')
  sfml_system = cpp.find_library('sfml-system', dirs : 'lib')
else
  sfml_dep = dependency('sfml', method : 'pkg-config')
endif

srcs = [
  'src/main.cpp'
]

executable('RainySeason',
           srcs,
           dependencies: [sfml_dep],
           install : true)