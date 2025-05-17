project('RainySeason', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

sfml_dep = dependency('sfml', method : 'pkg-config')

srcs = [
  'src/main.cpp'
]

executable('RainySeason',
           srcs,
           dependencies: [sfml_dep],
           install : true)
