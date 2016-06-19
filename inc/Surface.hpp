//
// Surface.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 16:41:14 2016 guillaume wilmot
// Last update Sun Jun 19 18:10:33 2016 guillaume wilmot
//

#ifndef SURFACE_HPP_
# define SURFACE_HPP_

# include <iostream>
# include "SDL.h"

class		Surface {
public:
  Surface(int = 0);
  Surface(SDL_Surface *, int = 0);
  ~Surface();

  int		create(Uint32, int, int, int, Uint32, Uint32, Uint32, Uint32);
  int		load(const std::string &);
  int		resize(float, float);

  void		clear(unsigned int);

  SDL_Surface	*get() const			{return (_surface);}

private:
  Surface(const Surface &)			{}
  Surface	&operator=(const Surface &)	{return (*this);}

  SDL_Surface	*_surface;
  int		_style;
};

#endif /* !SURFACE_HPP_ */
