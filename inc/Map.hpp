//
// Map.hh for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 13:05:37 2016 guillaume wilmot
// Last update Fri Jun 10 16:30:38 2016 guillaume wilmot
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <vector>
# include "Tile.hpp"
# include "ScopedPtr.hpp"

class		Map {
public:
  Map(int, int);
  Map();
  ~Map() {}

  void			setHeight(int s)		{_height = s;}
  void			setWidth(int s)			{_width = s;}
  void			render() const;

  int			init();
  int			getHeight() const		{return (_height);}
  int			getWidth() const		{return (_width);}
  Tile			*getTile(int x, int y) const	{return (_map[y][x].get());}

private:
  Map(const Map &)					{}
  Map			&operator=(const Map &)		{return (*this);}

  int							_width;
  int							_height;
  std::vector<std::vector<ScopedPtr<Tile> > >		_map;
};

#endif /* !MAP_HPP_ */
