//
// Tile.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:25:25 2016 guillaume wilmot
// Last update Sun Jun 26 07:01:03 2016 guillaume wilmot
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

  inline double	getTransformX(int i)
  {
    static const double	x[9] = {0, 1.0/6, 1.0/3, 1.0/6, 1.0/3, 1.0/2, 1.0/3, 1.0/2, 2.0/3};
    return (x[i]);
  }

  inline double	getTransformY(int i)
  {
    static const double	y[9] = {1.0/3, 1.0/6, 0, 1.0/2, 1.0/3, 1.0/6, 2.0/3, 1.0/2, 1.0/3};
    return (y[i]);
  }

  void		render(ZBuffer &buff, TextureManager &tmgr)
  {
    SDL_Rect		in;
    SDL_Rect		out;

    for (unsigned int i = 0; i < 7; i++)
      if (_rocks[i])
	{
	  TextureManager::surface	&tmp = tmgr.getRock(i);
	  if (tmp.texture && tmp.surface)
	    {
	      out.w = (1.0 * tmp.surface->w * Scale::get()._x) / 3.6;
	      out.h = (1.0 * tmp.surface->h * Scale::get()._y) / 3.6;
	      out.x = (_x + _y) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 8 +
		getTransformX(i) * Scale::get()._w;
	      out.y = (_mapWidth - (_y + 1) + _x) * 1.0 * Scale::get()._h / 4 +
		getTransformY(i) * Scale::get()._h / 2;
	      in.x = 0;
	      in.y = 0;
	      in.w = tmp.surface->w;
	      in.h = tmp.surface->h;
	      buff.add(tmp, &in, &out);
	    }
	}
    if (_active)
      {
	TextureManager::surface	&torch = tmgr["torches"];
	if (!torch.texture || !torch.surface)
	  return ;
	in.w = torch.surface->w / 5;
	in.h = torch.surface->h;
	in.x = (_frame % 5) * in.w;
	in.y = 0;
	out.w = (1.0 * torch.surface->w / 3 / 1.6 * Scale::get()._x);
	out.h = (1.0 * torch.surface->h / 1 * Scale::get()._y);
	out.x = (_x + _y) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 8 +
	  getTransformX(7) * Scale::get()._w;
	out.y = (_mapWidth - (_y + 1) + _x) * 1.0 * Scale::get()._h / 4 +
	  getTransformY(7) * Scale::get()._h / 2 - out.h / 1.2;
	buff.add(torch, &in, &out);
	if (_timer++ >= 10)
	  {
	    _frame++;
	    _timer = 0;
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
