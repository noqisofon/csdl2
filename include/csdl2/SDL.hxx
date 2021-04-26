#pragma once

#include "csdl2/csdl2_internal.h"

_CSDL2_BEGIN

/*!
 *
 */
class SDL {
public:
  /*!
   *
   */
  SDL(std::uint32_t flags = SDL_INIT_VIDEO);

  ~SDL();
};

_CSDL2_END
