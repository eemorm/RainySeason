project('RainySeason', 'cpp',
  version : '0.01',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

sfml_modules = ['graphics', 'window', 'system']
sfml_dep = dependency('sfml', modules: sfml_modules, required: true)
gl_dep = dependency('gl', required: true)

imgui_srcs = files(
  'src/ImGUI/imgui.cpp',
  'src/ImGUI/imgui_draw.cpp',
  'src/ImGUI/imgui_widgets.cpp',
  'src/ImGUI/imgui_tables.cpp'
)

imgui_sfml_srcs = files('src/ImGUI/imgui-SFML.cpp')

srcs = [
  'src/main.cpp',
  'src/Managers/Items/GroundItemManager.cpp',
  'src/Textures/Textures.cpp'
]

executable('RainySeason',
           srcs + imgui_srcs + imgui_sfml_srcs,
           dependencies: [sfml_dep, gl_dep],
           install : true,
           include_directories: ['src'])