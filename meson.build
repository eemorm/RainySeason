project('RainySeason', 'cpp',
  version : '0.01',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

sfml_modules = ['graphics', 'window', 'system']
sfml_dep = dependency('sfml', modules: sfml_modules, required: true)

srcs = [
  'src/main.cpp'
]

executable('RainySeason',
           srcs,
           dependencies: [sfml_dep],
           install : true)