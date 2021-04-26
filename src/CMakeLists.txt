set(srcs
  Color.cpp
  Point.cpp
  Rect.cpp
  Renderer.cpp
  SDL.cpp
  Size.cpp
  Window.cpp)

add_library(csdl2 STATIC ${srcs})
