//
// Map.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 14:22:12 2016 guillaume wilmot
// Last update Wed Jun 22 22:50:00 2016 guillaume wilmot
//

#include "Map.hpp"

Map::Map() : _map(0, std::vector<ScopedPtr<Tile> >(0)) {}


int		Map::init(int, int) {return (0);}

void		Map::render() const {}

void		Map::setRocks(int, int, int *) {}

void		Map::setUp(int, int, int, bool, bool) {}

void		Map::spawnEgg(int, int) {}

void		Map::removeRock(int, int, int) {}

void		Map::addRock(int, int, int) {}
