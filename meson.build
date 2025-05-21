project('RainySeason', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

cpp = meson.get_compiler('cpp')

if host_machine.system() == 'windows'
  sfml_graphics = cpp.find_library('sfml-graphics', dirs : 'lib')
  sfml_window = cpp.find_library('sfml-window', dirs : 'lib')
  sfml_system = cpp.find_library('sfml-system', dirs : 'lib')
  sfml_deps = [sfml_graphics, sfml_window, sfml_system]
else
  sfml_dep = dependency('sfml', method : 'pkg-config')
  sfml_deps = [sfml_dep]
endif

srcs = [
  'src/main.cpp'
]

executable('RainySeason',
  srcs,
  dependencies: sfml_deps,
  install: true)