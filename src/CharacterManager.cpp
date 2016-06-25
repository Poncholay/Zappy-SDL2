//
// CharacterManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 20 15:10:24 2016 guillaume wilmot
// Last update Sat Jun 25 15:28:47 2016 guillaume wilmot
//

#include <iostream>
#include "SDL_image.h"
#include "CharacterManager.hpp"
#include "TextureManager.hpp"
#include "Scale.hpp"

CharacterManager::CharacterManager() : _vector(LVLMAX)
{
  _n = LVLMAX;
  _a = NBANIM;
  _loaded = false;
  _r = NULL;
}

CharacterManager::~CharacterManager() {destroy();}

void			CharacterManager::destroy()
{
  for (auto it = _vector.begin(); it != _vector.end(); it++)
    {
      for (auto iit = (*it).begin(); iit != (*it).end(); iit++)
	SDL_DestroyTexture(*iit);
      (*it).clear();
    }
}

int			CharacterManager::getHeight(unsigned int lvl, unsigned int anim) const
{
  const static int	i[8][3] = {{4, 4, 4}, {4, 4, 4},
				   {4, 4, 4}, {4, 4, 4},
				   {4, 4, 4}, {4, 4, 4},
				   {4, 4, 4}, {4, 4, 4}};

  if (lvl >= _n || anim >= _a)
    return (1);
  return (i[lvl][anim]);
}

int			CharacterManager::getWidth(unsigned int lvl, unsigned int anim) const
{
  const static int	i[8][3] = {{15, 15, 20}, {9, 10, 15} ,
				   {8, 10, 15} , {6, 12, 15} ,
				   {11, 11, 16}, {10, 10, 15},
				   {10, 10, 15}, {10, 10, 15}};

  if (lvl >= _n || anim >= _a)
    return (1);
  return (i[lvl][anim]);
}

int			CharacterManager::init(Renderer *r)
{
  SDL_Surface		*tmpS;
  SDL_Texture		*tmpT;
  std::string		t;
  const char		*path[3] = {"standing", "moving", "dying"};

  if (_loaded)
    return (0);
  if (!r || !r->get())
    return (std::cerr << "No renderer" << std::endl, -1);
  for (unsigned int j = 0; j < _a; ++j)
    for (unsigned int i = 0; i < _n; ++i)
      {
	t = "./assets/textures/charsets/lvl" + std::to_string(i + 1) + "/" + path[j] + "/image.png";
	if (!(tmpS = IMG_Load(t.c_str())))
	  return (std::cerr << "Cannot load " << t << std::endl, -1);
	if (!(tmpT = SDL_CreateTextureFromSurface(r->get(), tmpS)))
	  return (-1);
	SDL_FreeSurface(tmpS);
	_vector[i].push_back(tmpT);
      }
  _loaded = true;
  return (0);
}
