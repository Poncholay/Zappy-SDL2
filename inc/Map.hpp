//
// Map.hh for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 13:05:37 2016 guillaume wilmot
// Last update Fri Jun 24 00:39:14 2016 guillaume wilmot
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <vector>
# include "Tile.hpp"
# include "ScopedPtr.hpp"
# include "ZBuffer.hpp"

class		Map {
public:
  Map();
  ~Map() {}

  void			setHeight(int s)		{_h = s;}
  void			setWidth(int s)			{_w = s;}

  void			render(ZBuffer &) const;
  void			setRocks(unsigned int, unsigned int, int *);
  void			setUp(unsigned int, unsigned int, int, bool, bool);
  void			spawnEgg(unsigned int, unsigned int);
  void			removeRock(unsigned int, unsigned int, int);
  void			addRock(unsigned int, unsigned int, int);
  void			init();

  unsigned int		getHeight() const		{return (_h);}
  unsigned int		getWidth() const		{return (_w);}
  Tile			*getTile(int x, int y) const	{return (_map[y][x].get());}

private:
  void			create(unsigned int, unsigned int);

  Map(const Map &)					{}
  Map			&operator=(const Map &)		{return (*this);}

  unsigned int						_w;
  unsigned int						_h;
  std::vector<std::vector<ScopedPtr<Tile> > >		_map;
};

#endif /* !MAP_HPP_ */
