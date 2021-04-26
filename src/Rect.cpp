#include <cstddef>
#include <cstdint>

#ifdef _MSC_VER
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/csdl2_internal.h"
#include "csdl2/Point.hxx"
#include "csdl2/Size.hxx"
#include "csdl2/Rect.hxx"

_CSDL2_BEGIN

Rect::Rect()
    : x(0)
    , y(0)
    , width(0)
    , height(0) {
}
Rect::Rect(std::int32_t _x,
           std::int32_t _y,
           std::uint32_t _width,
           std::uint32_t _height)
    : x(_x)
    , y(_y)
    , width(_width)
    , height(_height) {
}
Rect::Rect(const Point &point, const Size &size)
    : x(point.x)
    , y(point.y)
    , width(size.width)
    , height(size.height) {
}

void Rect::copyTo(SDL_Rect *const raw_rect) {
    raw_rect->x = x;
    raw_rect->y = y;
    raw_rect->w = width;
    raw_rect->h = height;
}

void Rect::assign(std::int32_t _x,
                  std::int32_t _y,
                  std::uint32_t _width,
                  std::uint32_t _height) {
    x      = _x;
    y      = _y;
    width  = _width;
    height = _height;
}

_CSDL2_END
