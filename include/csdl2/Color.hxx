#pragma once

#include "csdl2/csdl2_internal.h"

#include <cstddef>
#include <cstdint>

_CSDL2_BEGIN

/*!
 *
 */
struct Color {
    std::uint8_t red;
    std::uint8_t blue;
    std::uint8_t green;
    std::uint8_t alpha;

    Color();
    Color(std::uint8_t r, std::uint8_t b, std::uint8_t g, std::uint8_t a = 255);

    void assign(std::uint8_t r, std::uint8_t b, std::uint8_t g, std::uint8_t a = 255);
};

_CSDL2_END
