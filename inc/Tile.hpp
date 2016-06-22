//
// Tile.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:25:25 2016 guillaume wilmot
// Last update Wed Jun 22 22:54:12 2016 guillaume wilmot
//

#ifndef TILE_HPP_
# define TILE_HPP_

# include <vector>

class		Tile {
public:
  Tile() {}
  ~Tile() {}
private:
  Tile(const Tile &) {}
  Tile	&operator=(const Tile &) {return (*this);}

  int		rocks[7];
  int		up;
  bool		res;
};

#endif /* !TILE_HPP_ */
