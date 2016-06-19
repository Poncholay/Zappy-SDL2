//
// Renderer.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 15:49:13 2016 guillaume wilmot
// Last update Sun Jun 19 16:25:14 2016 guillaume wilmot
//

#ifndef RENDERER_HPP_
# define RENDERER_HPP_

# include "SDL.h"

class		Renderer {
public:
  Renderer() {_renderer = NULL;}
  Renderer(SDL_Window *);
  ~Renderer();

  int		init(SDL_Window *);
  int		setRenderDrawColor(Uint8, Uint8, Uint8, Uint8);
  int		renderClear();
  int		renderCopy(SDL_Texture *, SDL_Rect, SDL_Rect);
  void		renderPresent();

  SDL_Renderer	*get() const			{return (_renderer);}

private:
  Renderer(const Renderer &)			{}
  Renderer	&operator=(const Renderer &)	{return (*this);}

  SDL_Renderer	*_renderer;
};

#endif /* !RENDERER_HPP_ */
