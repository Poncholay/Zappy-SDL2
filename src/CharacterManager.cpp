//
// CharacterManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 20 15:10:24 2016 guillaume wilmot
// Last update Mon Jun 20 21:18:58 2016 guillaume wilmot
//

#include <iostream>
#include "SDL_image.h"
#include "CharacterManager.hpp"
#include "TextureManager.hpp"

CharacterManager::CharacterManager(int n, int a) : _vector(n) {_n = n; _a = a;}

CharacterManager::~CharacterManager()
{
  for (auto it = _vector.begin(); it != _vector.end(); it++)
    for (auto iit = (*it).begin(); iit != (*it).end(); iit++)
      SDL_DestroyTexture(*iit);
}

int		CharacterManager::init(int scale, Renderer *r)
{
  SDL_Surface	*tmpS;
  SDL_Texture	*tmpT;
  std::string	t;
  const char	*path[3] = {"standing", "moving", "dying"};

  if (!r)
    return (std::cerr << "No renderer" << std::endl, -1);
  for (unsigned int i = 0; i < _n; ++i)
    for (unsigned int j = 0; j < _a; ++j)
      {
	t = "./assets/textures/charsets/lvl" + std::to_string(i + 1) + "/" + path[j] + "/image.png";
	if (!(tmpS = IMG_Load(t.c_str())))
	  return (std::cerr << "Cannot load " << t << std::endl, -1);
	if (!(tmpS = TextureManager::resize(tmpS, scale, scale, 2)))
	  return (-1);
	if (!(tmpT = SDL_CreateTextureFromSurface(r->get(), tmpS)))
	  return (std::cerr << "Could not create texture" << std::endl, -1);
	SDL_FreeSurface(tmpS);
	_vector[i].push_back(tmpT);
      }
  return (0);
}
