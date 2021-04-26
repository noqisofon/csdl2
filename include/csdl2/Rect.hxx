#include "csdl2/csdl2_internal.h"

#include <cstddef>
#include <cstdint>

#include "csdl2/Point.hxx"
#include "csdl2/Size.hxx"

_CSDL2_BEGIN

/*!
 *
 */
struct Rect {
    std::int32_t x;
    std::int32_t y;
    std::uint32_t width;
    std::uint32_t height;

    Rect();
    Rect(std::int32_t _x,
         std::int32_t _y,
         std::uint32_t _width,
         std::uint32_t _height);
    Rect(const Point &point, const Size &size);

    /*!
     *
     */
    void  copyTo(SDL_Rect *const raw_rect);

    /*!
     *
     */
    void assign(std::int32_t _x,
                std::int32_t _y,
                std::uint32_t _width,
                std::uint32_t _height);
};

_CSDL2_END
