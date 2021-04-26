#include <cstddef>
#include <cstdint>
#include <string>

#ifdef _MSC_VER
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif /* def _MSC_VER */

#include "csdl2/Point.hxx"
#include "csdl2/Size.hxx"
#include "csdl2/Window.hxx"

_CSDL2_BEGIN

Window::Window(std::string &title, std::uint32_t width, std::uint32_t height)
    : Handle(NULL)
    , title_(title)
    , x_(SDL_WINDOWPOS_UNDEFINED)
    , y_(SDL_WINDOWPOS_UNDEFINED)
    , width_(width)
    , height_(height)
    , flags_(SDL_WINDOW_SHOWN) {
}

Window::~Window() {
    destroy();
}

bool Window::create() {
    handle_ = ::SDL_CreateWindow(title_.c_str(), x_, y_, width_, height_, flags_);

    if (handle_ == NULL) {
        created_ = false;
    } else {
        created_ = true;
        destroied_ = false;
    }

    return created_;
}

void Window::destroy() {
    if (handle_) {
        ::SDL_DestroyWindow(handle_);
        handle_ = NULL;
        destroied_ = true;
    }
}

Point Window::getPosition() {
    std::int32_t x;
    std::int32_t y;

    ::SDL_GetWindowPosition(handle_, &x, &y);

    x_ = x;
    y_ = y;

    return Point { x_, y_ };
}

Size Window::getSize() {
    std::int32_t w;
    std::int32_t h;

    ::SDL_GetWindowSize(handle_, &w, &h);

    width_ = static_cast<std::uint32_t>(w);
    height_ = static_cast<std::uint32_t>(h);

    return Size { width_, height_ };
}

_CSDL2_END
