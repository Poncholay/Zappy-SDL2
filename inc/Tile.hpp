//
// Tile.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:25:25 2016 guillaume wilmot
// Last update Sun Jun 26 01:52:37 2016 guillaume wilmot
//

#ifndef TILE_HPP_
# define TILE_HPP_

# include <vector>
# include "ZBuffer.hpp"
# include "Scale.hpp"

class		Tile {
public:
  Tile(int x, int y, int w) {_x = x; _y = y; _mapWidth = w; memset(&_rocks, 0, sizeof(_rocks)); _frame = 0; _timer = 0; _active = 0;}
  ~Tile() {}

  void		setRocks(int *r) {for (int i = 0; i < 7; i++) _rocks[i] = r[i];}
  void		setUp(int lvl, int active, bool res) {_lvl = lvl; _active = active; _res = res;}
  void		addRock(int id, bool add) {_rocks[id] += (add ? -1 : 1);}
  void		render(ZBuffer &buff, TextureManager &tmgr)
  {
    for (unsigned int i = 0; i < 7; i++)
      {
	TextureManager::surface	&tmp = tmgr.getRock(i);
	SDL_Rect		in;
	SDL_Rect		out;

	if (!tmp.texture || !tmp.surface)
	  continue ;
	for (int j = 0; j < _rocks[i]; j++)
	  {
	    out.w = (1.0 * tmp.surface->w * Scale::get()._x) / 2.7;
	    out.h = (1.0 * tmp.surface->h * Scale::get()._y) / 2.7;
	    out.x = (_x + _y) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 4 + (1.0 * i * Scale::get()._w / 14);
	    out.y = (_mapWidth - (_y + 1) + _x) * 1.0 * Scale::get()._h / 4 +
	      (j * Scale::get()._h / 2 / _rocks[i]) + Scale::get()._h / 8 - out.h / 2;

	    in.x = 0;
	    in.y = 0;
	    in.w = tmp.surface->w;
	    in.h = tmp.surface->h;
	    buff.add(tmp, &in, &out);
	  }
	if (_active)
	  {
	    TextureManager::surface	&torch = tmgr["torches"];
	    if (!torch.texture || !torch.surface)
	      continue ;
	    in.w = torch.surface->w / 5;
	    in.h = torch.surface->h;
	    in.x = (_frame % 5) * in.w;
	    in.y = 0;
	    out.w = (1.0 * torch.surface->w / 5 / 1.6 * Scale::get()._x);
	    out.h = (1.0 * torch.surface->h / 1.6 * Scale::get()._y);
	    out.x = (_x + _y) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 8;
	    out.y = (_mapWidth - (_y + 1) + _x) * 1.0 * Scale::get()._h / 4;
	    buff.add(torch, &in, &out);
	    if (_timer++ >= 60)
	      {
		_frame++;
		_timer = 0;
	      }
	  }
      }
  }

private:
  Tile(const Tile &) {}
  Tile	&operator=(const Tile &) {return (*this);}

  int		_x;
  int		_y;
  int		_mapWidth;
  int		_rocks[7];

  int		_lvl;
  int		_active;
  bool		_res;
  int		_frame;
  int		_timer;
};

#endif /* !TILE_HPP_ */
