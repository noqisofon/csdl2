#include <cstddef>
#include <cstdint>

#ifdef _MSC_VER
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/csdl2_internal.h"

#include "csdl2/Point.hxx"

_CSDL2_BEGIN

Point::Point() : x(0), y(0) {
}
Point::Point(std::int32_t x, std::int32_t y): x(x), y(y) {
}

void Point::copyTo(SDL_Point *const raw_point) {
    raw_point->x = x;
    raw_point->y = y;
}

void Point::assign(std::int32_t x, std::int32_t y) {
    this->x = x;
    this->y = y;
}

_CSDL2_END
