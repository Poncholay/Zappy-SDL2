//
// Displayer.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:23:17 2016 guillaume wilmot
// Last update Mon Jun 20 11:10:31 2016 guillaume wilmot
//

#ifndef DISPLAYER_HPP_
# define DISPLAYER_HPP_

# include "SDL.h"
# include "Mutex.hpp"
# include "ShapedWindow.hpp"
# include "ZBuffer.hpp"
# include "TextureManager.hpp"

class		Displayer {
public:
  Displayer();
  ~Displayer()								{}

  static void		create();
  int			start();

private:
  Displayer(const Displayer &) : _win("Zappy"), _zbuff(WINX, WINY)	{}
  Displayer		&operator=(const Displayer &)			{return (*this);}

  Mutex			_mutex;
  ShapedWindow		_win;
  ZBuffer		_zbuff;
  TextureManager	_tmgr;
  TextureManager	_tmgrChar;
  //Map		_map;
};

#endif /* !DISPLAYER */
