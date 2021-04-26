#include <cstddef>
#include <cstdint>

#ifdef _MSC_VER
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/csdl2_internal.h"
#include "csdl2/SDL.hxx"

_CSDL2_BEGIN


SDL::SDL(std::uint32_t flags) {
    std::int32_t answer = ::SDL_Init( flags );
}

SDL::~SDL() {
    ::SDL_Quit();
}


_CSDL2_END
