#pragma once

#include <string>

#include "csdl2/Handle.hxx"
#include "csdl2/csdl2_internal.h"

_CSDL2_BEGIN

class Size;

/*!
 *
 */
class Window : public Handle<SDL_Window> {
public:
    /*!
    *
    */
    Window(std::string &title, std::uint32_t width, std::uint32_t height);

    /*!
    *
    */
    ~Window();

    /*!
    *
    */
    virtual bool create();

    /*!
    *
    */
    virtual void destroy();

    /*!
     *
     */
    Point getPosition();

    /*!
    *
    */
    Size getSize();

private:
    std::string title_;
    std::int32_t x_;
    std::int32_t y_;
    std::uint32_t width_;
    std::uint32_t height_;
    std::uint32_t flags_;
};

_CSDL2_END
