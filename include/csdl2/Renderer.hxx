#pragma once

#include <memory>

#include "csdl2/Handle.hxx"

_CSDL2_BEGIN

class Window;
class Rect;

/*!
 *
 */
class Renderer : public Handle<SDL_Renderer> {
public:
  /*!
   *
   */
  Renderer(std::shared_ptr<Window> &window, std::int32_t index = -1,
           std::uint32_t flags = SDL_RENDERER_PRESENTVSYNC);

  /*!
   *
   */
  ~Renderer();

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
  void setRenderDrawColor(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);
  /*!
   *
   */
  void setRenderDrawColor(Color& draw_color);

  /*!
   *
   */
  void fullRect(const Rect &rect);

  /*!
   *
   */
  void present();

  /*!
   *
   */
  void clear();

private:
  std::shared_ptr<Window> window_;
  std::int32_t index_;
  std::uint32_t flags_;
};

_CSDL2_END
