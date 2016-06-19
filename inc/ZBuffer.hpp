//
// ZBuffer.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 13 15:28:28 2016 guillaume wilmot
// Last update Sun Jun 19 16:23:36 2016 guillaume wilmot
//

#ifndef ZBUFFER_HPP_
# define ZBUFFER_HPP_

# include <vector>
# include "TextureManager.hpp"
# include "SDL.h"

class		ZBuffer {
public:
  ZBuffer(int, int);
  ~ZBuffer();
  ZBuffer(const ZBuffer &);
  ZBuffer	&operator=(const ZBuffer &);

  typedef struct		z_buffer {
    TextureManager::surface	surface;
    SDL_Rect			in;
    SDL_Rect			out;
    int				layer;
  }				buff;

  void		add(TextureManager::surface &, SDL_Rect *, SDL_Rect *, int = 0);
  SDL_Surface	*renderToSurface();
  void		render();

  void				setRenderer(Renderer *r)	{_renderer = r;}

  SDL_Surface			*getSurface()	const	{return (_surface);}
  std::vector<buff>		getBuffer()	const	{return (_buffer);}
  static bool			sort(buff, buff);

  void				incX(int t)		{_x += t;}
  void				incY(int t)		{_y += t;}
  void				center()		{_x = 0; _y = 0;}

private:

  SDL_Surface		*_surface;
  Renderer		*_renderer;
  std::vector<buff>	_buffer;
  int			_x;
  int			_y;
};

#endif /* !ZBUFFER_HPP_ */
