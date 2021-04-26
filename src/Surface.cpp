#include <cstddef>
#include <cstdint>

#ifdef _MSC_VER
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/csdl2_internal.h"
#include "csdl2/Surface.hxx"

_CSDL2_BEGIN

Surface::Surface() : Freeable(NULL) {}

Surface::~Surface() {
    free();
}

bool Surface::createRGB(std::int32_t width,
                        std::int32_t height,
                        std::int32_t depth,
                        std::uint32_t flags) {
    std::uint32_t r_mask = 0,
                  g_mask = 0,
                  b_mask = 0,
                  a_mask = 0;

    /** SDL はピクセルを 32 bit の値として解釈するよ。
        よって、マスクはマシンのエンディアン(バイト順)に依存するよ。 */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    r_mask = 0xff000000;
    g_mask = 0x00ff0000;
    b_mask = 0x0000ff00;
    a_mask = 0x000000ff;
#else   /* ^^^ SDL_BYTEORDER == SDL_BIG_ENDIAN / SDL_BYTEORDER == SDL_LITTLE_ENDIAN */
    r_mask = 0x000000ff;
    g_mask = 0x0000ff00;
    b_mask = 0x00ff0000;
    a_mask = 0xff000000;
#endif  /* SDL_BYTEORDER == SDL_BIG_ENDIAN */

    return createRGB(width,
                     height,
                     depth,
                     r_mask,
                     g_mask,
                     b_mask,
                     a_mask,
                     flags);
}

bool Surface::createRGB(std::int32_t width,
                        std::int32_t height,
                        std::int32_t depth,
                        std::uint32_t r_mask,
                        std::uint32_t g_mask,
                        std::uint32_t b_mask,
                        std::uint32_t a_mask,
                        std::uint32_t flags) {
    handle_ =  ::SDL_CreateRGBSurface( flags,
                                       width,
                                       height,
                                       depth,
                                       r_mask,
                                       g_mask,
                                       b_mask,
                                       a_mask );
    if ( !handle_ ) {

        return false;
    }
    return true;
}

void Surface::free() {
    if (!handle_) {
        return ;
    }
    ::SDL_FreeSurface(handle_);
}

_CSDL2_END
