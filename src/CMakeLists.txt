set(srcs
  Color.cpp
  Point.cpp
  Rect.cpp
  Renderer.cpp
  SDL.cpp
  Size.cpp
  Surface.cpp
  Window.cpp)

add_library(csdl2 STATIC ${srcs})
