project('RainySeason', 'cpp',
  version : '0.01',
  default_options : ['warning_level=3', 'cpp_std=c++20']
)

sfml_modules = ['graphics', 'window', 'system']
sfml_dep = dependency('sfml', modules: sfml_modules, required: true)

imgui_dep = subproject('ImGUI').get_variable('imgui_dep_wrap')

srcs = [
  'src/main.cpp'
]

executable('RainySeason',
  srcs,
  dependencies: [sfml_dep, imgui_dep],
  install: true
)