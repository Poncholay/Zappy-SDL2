//
// TextureManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 12 19:32:55 2016 guillaume wilmot
// Last update Mon Jun 20 17:48:59 2016 guillaume wilmot
//

#include <iostream>
#include "SDL2_rotozoom.h"
#include "SDL_image.h"
#include "TextureManager.hpp"

TextureManager::~TextureManager() {destroy();}

void		TextureManager::destroy()
{
  for (auto it = _map.begin(); it != _map.end(); it++)
    for (unsigned int i = 0; i < (*it).second.size(); i++)
      {
	if ((*it).second[i].surface)
	  SDL_FreeSurface((*it).second[i].surface);
	if ((*it).second[i].texture)
	  SDL_DestroyTexture((*it).second[i].texture);
      }
  _map.clear();
}

int		TextureManager::init(int scale)
{
  if (scale != _scale && _scale != -1)
    destroy();
  _scale = scale;
  if (-1 == add("cube", "./assets/textures/cube.png", scale, scale, 1))
    return (-1);
  for (unsigned int i = 1; i < 5; i++)
    if (-1 == add("tree", "./assets/textures/tree" + std::to_string(i) + ".png", scale, scale, 2))
      return (-1);
  for (unsigned int i = 1; i < 6; i++)
    if (-1 == add("bush", "./assets/textures/weed" + std::to_string(i) + ".png", scale/2, scale/2, 1))
      return (-1);
  for (unsigned int i = 1; i < 7; i++)
    if (-1 == add("bush", "./assets/textures/bush" + std::to_string(i) + ".png", scale, scale, 1))
      return (-1);
  for (unsigned int i = 2; i < 5; i++)
    if (-1 == add("vine", "./assets/textures/vine" + std::to_string(i) + ".png", scale, scale, 2))
      return (-1);
  return (0);
}

SDL_Surface	*TextureManager::resize(SDL_Surface *s, float x, float y, int scale)
{
  SDL_Surface	*ret;
  float		x2;
  float		y2;

  x2 = 1.0 * x / s->w > 1 ? 1 : 1.0 * x / s->w;
  y2 = 1.0 * y / s->h > 1 ? 1 : 1.0 * y / s->h;
  if (scale == 2)
    x2 = 1.0 * y2 * (1.0 * s->w / s->h);
  if (!(ret = zoomSurface(s, x2, y2, 0)))
    return (NULL);
  SDL_FreeSurface(s);
  return (ret);
}

int		TextureManager::add(const std::string &key, const std::string &name, float x, float y, int scale)
{
  SDL_Surface	*surface;

  if (!(surface = IMG_Load(name.c_str())))
    {
      std::cerr << "Could not load " << name << std::endl;
      return (-1);
    }
  if (scale)
    if (!(surface = resize(surface, x, y, scale)))
      return (-1);
  return (add(key, surface));
}

int		TextureManager::add(const std::string &key, SDL_Surface *s)
{
  surface	su;

  memset(&su, 0, sizeof(su));
  su.surface = s;
  if (_r)
    su.texture = SDL_CreateTextureFromSurface(_r->get(), s);
  _map[key].push_back(su);
  return (0);
}

int		TextureManager::update()
{
  for (auto it = _map.begin(); it != _map.end(); it++)
    for (unsigned int i = 0; i < (*it).second.size(); i++)
      if (!_r || !((*it).second[i].texture = SDL_CreateTextureFromSurface(_r->get(), (*it).second[i].surface)))
	return (-1);
  _cmgr.init(_scale, _r);
  return (0);
}

TextureManager::surface		&TextureManager::get(const std::string &key)
{
  return (_map[key][rand() % _map[key].size()]);
}

TextureManager::surface		&TextureManager::operator[](const std::string &key)
{
  return (get(key));
}

std::vector<TextureManager::surface>	&TextureManager::getV(const std::string &key)
{
  return (_map[key]);
}
