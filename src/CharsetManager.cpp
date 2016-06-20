//
// CharsetManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 20 15:10:24 2016 guillaume wilmot
// Last update Mon Jun 20 15:40:06 2016 guillaume wilmot
//

#include <iostream>
#include "SDL_image.h"
#include "CharsetManager.hpp"

CharsetManager::CharsetManager(int n, int a) : _vector(n) {_n = n; _a = a;}

CharsetManager::~CharsetManager()
{
  for (auto it = _vector.begin(); it != _vector.end(); it++)
    for (auto iit = (*it).begin(); iit != (*it).end(); iit++)
      SDL_DestroyTexture(*iit);
}

int		CharsetManager::init(int)
{
  SDL_Surface	*tmpS;
  // SDL_Texture	*tmpT;
  std::string	t;
  const char	*path[3] = {"standing", "moving", "dying"};

  for (unsigned int i = 0; i < _n; ++i)
    for (unsigned int j = 0; j < _a; ++j)
      {
	t = "./assets/textures/charsets/lvl" + std::to_string(i + 1) + "/" + path[j] + "/image.png";
	if (!(tmpS = IMG_Load(t.c_str())))
	  return (std::cerr << "Cannot load " << t << std::endl, -1);
	// _vector[i].push_back(SDL_);
      }
  return (0);
}
