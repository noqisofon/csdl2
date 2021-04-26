#include <cstddef>
#include <cstdint>

#ifdef _MSC_VER
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/csdl2_internal.h"

#include "csdl2/Rect.hxx"

#include "csdl2/Color.hxx"

_CSDL2_BEGIN

Color::Color()
    : red(0)
    , blue(0)
    , green(0)
    , alpha(255) {
}
Color::Color(std::uint8_t r, std::uint8_t b, std::uint8_t g, std::uint8_t a)
    : red(r)
    , blue(b)
    , green(g)
    , alpha(255) {
}

void Color::assign(std::uint8_t r, std::uint8_t b, std::uint8_t g, std::uint8_t a) {
    red = r;
    blue = b;
    green = g;
    alpha = a;
}

_CSDL2_END
