#pragma once

#include "csdl2/csdl2_internal.h"

#include <cstddef>
#include <cstdint>


_CSDL2_BEGIN


struct Point {
    std::int32_t x;
    std::int32_t y;

    Point();
    Point(std::int32_t x, std::int32_t y);

    void copyTo(SDL_Point * const raw_point);
    void assign(std::int32_t x, std::int32_t y);
};


_CSDL2_END
