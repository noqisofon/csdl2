#pragma once

#include <cstddef>
#include <cstdint>

#include "csdl2/csdl2_internal.h"
#include "csdl2/Freeable.hxx"

_CSDL2_BEGIN

class Rect;

/*!
 *
 */
class Surface : public Freeable<SDL_Surface> {
public:
    /*!
     *
     */
    Surface();

    /*!
     *
     */
    ~Surface();

    /*!
     *
     */
    bool createRGB(std::int32_t width,
                   std::int32_t height,
                   std::int32_t depth = 32,
                   std::uint32_t flags = 0);
    /*!
     *
     */
    bool createRGB(std::int32_t width,
                   std::int32_t height,
                   std::int32_t depth,
                   std::uint32_t r_mask,
                   std::uint32_t g_mask,
                   std::uint32_t b_mask,
                   std::uint32_t a_mask,
                   std::uint32_t flags = 0);

    /*!
     *
     */
    virtual void free();

private:
    std::int32_t width_;
    std::int32_t height_;
    std::int32_t depth_;
};

_CSDL2_END
