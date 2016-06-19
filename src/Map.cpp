//
// Map.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:22:12 2016 guillaume wilmot
// Last update Fri Jun 10 16:32:22 2016 guillaume wilmot
//

#include "Map.hpp"

Map::Map() : _map(0, std::vector<ScopedPtr<Tile> >(0)) {}

Map::Map(int width, int height) : _map(height, std::vector<ScopedPtr<Tile> >(width))
{
  _width = width;
  _height = height;
}

int		Map::init() {return (0);}

void		Map::render() const {}
