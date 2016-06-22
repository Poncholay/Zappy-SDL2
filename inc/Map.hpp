//
// Map.hh for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 13:05:37 2016 guillaume wilmot
// Last update Wed Jun 22 22:49:38 2016 guillaume wilmot
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <vector>
# include "Tile.hpp"
# include "ScopedPtr.hpp"

class		Map {
public:
  Map();
  ~Map() {}

  void			setHeight(int s)		{_h = s;}
  void			setWidth(int s)			{_w = s;}

  void			render() const;
  void			setRocks(int, int, int *);
  void			setUp(int, int, int, bool, bool);
  void			spawnEgg(int, int);
  void			removeRock(int, int, int);
  void			addRock(int, int, int);
  int			init(int, int);


  int			getHeight() const		{return (_h);}
  int			getWidth() const		{return (_w);}
  Tile			*getTile(int x, int y) const	{return (_map[y][x].get());}

private:
  Map(const Map &)					{}
  Map			&operator=(const Map &)		{return (*this);}

  int							_w;
  int							_h;
  std::vector<std::vector<ScopedPtr<Tile> > >		_map;
};

#endif /* !MAP_HPP_ */
