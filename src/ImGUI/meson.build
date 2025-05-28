project('ImGUI', 'cpp')

imgui_sources = files(
  'imgui.cpp',
  'imgui_draw.cpp',
  'imgui_widgets.cpp',
  'imgui_tables.cpp',
  'imgui-SFML.cpp'
)

imgui_dep = static_library('imgui',
  imgui_sources,
  include_directories: include_directories('.'),
  dependencies: dependency('sfml', modules : ['graphics', 'window', 'system'], required: true)
)

imgui_inc = include_directories('.')

imgui_dep_wrap = declare_dependency(
  include_directories: imgui_inc,
  link_with: imgui_dep
)