//
// Tile.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:25:25 2016 guillaume wilmot
// Last update Thu Jun 23 18:46:25 2016 guillaume wilmot
//

#ifndef TILE_HPP_
# define TILE_HPP_

# include <vector>

class		Tile {
public:
  Tile(int x, int y) {_x = x; _y = y;}
  ~Tile() {}

  void		setRocks(int *r) {for (int i = 0; i < 7; i++) _rocks[i] = r[i];}
  void		setUp(int lvl, int active, bool res) {_lvl = lvl; _active = active; _res = res;}
  void		addRock(int id, bool add) {_rocks[id] += (add ? -1 : 1);}

private:
  Tile(const Tile &) {}
  Tile	&operator=(const Tile &) {return (*this);}

  int		_x;
  int		_y;
  int		_rocks[7];
  int		_lvl;
  int		_active;
  bool		_res;
};

#endif /* !TILE_HPP_ */
