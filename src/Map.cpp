//
// Map.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:22:12 2016 guillaume wilmot
// Last update Sun Jun 26 04:43:40 2016 guillaume wilmot
//

#include "Map.hpp"

Map::Map() {}

void		Map::render(ZBuffer &z, TextureManager &tmgr) const
{
  for (unsigned int i = 0; i < _h; i++)
    for (unsigned int j = 0; j < _w; j++)
      _map[i][j].get()->render(z, tmgr);
}

void		Map::init()
{
  if (_w == 0 || _h == 0)
    return ;
  _map = std::vector<std::vector<ScopedPtr<Tile> > >(_h);
  for (unsigned int i = 0; i < _h; i++)
    _map[i] = std::vector<ScopedPtr<Tile> >(_w);
  for (unsigned int i = 0; i < _h; i++)
    for (unsigned int j = 0; j < _w; j++)
      _map[i][j].set(new Tile(j, i, _w));
}

void		Map::setRocks(unsigned int x, unsigned int y, int *rocks)
{
  if (x >= _w || y >= _h)
    return ;
  create(x, y);
  _map[y][x].get()->setRocks(rocks);
}

void		Map::setUp(unsigned int x, unsigned int y, int lvl, bool active, bool result)
{
  if (x >= _w || y >= _h)
    return ;
  create(x, y);
  _map[y][x].get()->setUp(lvl, active, result);
}

void		Map::removeRock(unsigned int x, unsigned int y, int id)
{
  if (x >= _w || y >= _h)
    return ;
  create(x, y);
  _map[y][x].get()->addRock(id, false);
}

void		Map::addRock(unsigned int x, unsigned int y, int id)
{
  if (x >= _w || y >= _h)
    return ;
  create(x, y);
  _map[y][x].get()->addRock(id, true);
}

void		Map::create(unsigned int x, unsigned int y)
{
  if (x >= _w || y >= _h)
    return ;
  if (!_map[y][x].get())
    _map[y][x].set(new Tile(x, y, _w));
}
