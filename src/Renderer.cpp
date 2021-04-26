#include <cstddef>
#include <cstdint>
#include <memory>

#ifdef _MSC_VER
#   include <SDL.h>
#else
#   include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/csdl2_internal.h"

#include "csdl2/Color.hxx"
#include "csdl2/Rect.hxx"
#include "csdl2/Window.hxx"

#include "csdl2/Renderer.hxx"

_CSDL2_BEGIN

Renderer::Renderer(std::shared_ptr<Window>& window, std::int32_t index,
    std::uint32_t flags)
    : Handle(NULL)
    , window_(window)
    , index_(index)
    , flags_(flags)
{
}

Renderer::~Renderer() { destroy(); }

bool Renderer::create()
{
    handle_ = ::SDL_CreateRenderer(window_->getHandle(), index_, flags_);
    if (handle_ == NULL) {
    } else {
        created_ = true;
    }
    return created_;
}

void Renderer::destroy()
{
    if (handle_) {
        ::SDL_DestroyRenderer(handle_);
        handle_ = NULL;
        destroied_ = true;
    }
}

void Renderer::setRenderDrawColor(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) {
  if ( !handle_ ) {
    return ;
  }

  ::SDL_SetRenderDrawColor( handle_,
			    red,
			    green,
			    blue,
			    alpha );
}

void Renderer::setRenderDrawColor(Color& draw_color) {
  if ( !handle_ ) {
    return ;
  }

  ::SDL_SetRenderDrawColor( handle_,
			    draw_color.red,
			    draw_color.green,
			    draw_color.blue,
			    draw_color.alpha );
}

void Renderer::fullRect(const Rect &rect) {
  if ( !handle_ ) {
    return ;
  }

  ::SDL_Rect raw_rect {
    rect.x,
    rect.y,
    static_cast<std::int32_t>( rect.width ),
    static_cast<std::int32_t>( rect.height )
  };

  ::SDL_RenderFillRect( handle_, &raw_rect );
}

void Renderer::present() {
  if ( !handle_ ) {
    return ;
  }

  ::SDL_RenderPresent( handle_ );
}

void Renderer::clear()
{
  if ( !handle_ ) {
    return ;
  }

  ::SDL_RenderClear( handle_ );
}

_CSDL2_END
