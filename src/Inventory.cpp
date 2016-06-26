//
// Inventory.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 26 16:51:25 2016 guillaume wilmot
// Last update Sun Jun 26 20:32:51 2016 guillaume wilmot
//

#include <iostream>
#include "Inventory.hpp"
#include "SDL_image.h"
#include "SDL_ttf.h"

Inventory::Inventory() {_id = -1;}
Inventory::~Inventory() {if (_win) SDL_DestroyWindow(_win); TTF_Quit(); _loaded = false;}

int		Inventory::init()
{
  SDL_Surface	*tmp;

  if (!(tmp = IMG_Load("./assets/textures/inv.png")) ||
      !(_win = SDL_CreateWindow("Inventory", 0, 0, tmp->w, tmp->h, 0)) ||
      _renderer.init(_win) == -1 ||
      !(_back = SDL_CreateTextureFromSurface(_renderer.get(), tmp)) ||
      TTF_Init() == -1 ||
      !(_font = TTF_OpenFont("./assets/font.ttf", 40)))
    return (std::cerr << "Could not init inventory" << std::endl, -1);
  SDL_FreeSurface(tmp);
  _renderer.setRenderDrawColor(0, 0, 0, 0);
  TTF_SetFontHinting(_font, TTF_HINTING_LIGHT);

  Uint32                pixelFormat = 0;

  memset(&_black, 0, sizeof(SDL_Color));
  memset(&_dims, 0, sizeof(SDL_Rect));
  SDL_QueryTexture(_back, &pixelFormat, NULL, &_dims.w, &_dims.h);
  _loaded = true;
  return (0);
}

int		Inventory::render(std::map<int, Charset *> &players, CharacterManager &cmgr)
{
  static const int	x[8] {60, 140, 225, 305, 100, 185, 270, 350};
  static const int	y[8] {90, 90, 90, 90, 190, 190, 190, 230};
  static bool		i = false;
  if (!i)
    {
      cmgr.initFaces(&_renderer);
      i = true;
    }

  if (!_loaded)
    return (-1);
  _renderer.renderClear();
  _renderer.renderCopy(_back, _dims, _dims);
  Charset		*c;
  if ((c = players[_id]))
    {
      SDL_Texture		*texture;
      SDL_Rect			src;
      SDL_Rect			dest;
      for (unsigned int i = 0; i < 7; i++)
	{
	  SDL_Surface		*text;

	  if (!(text = TTF_RenderText_Blended(_font, std::to_string(c->getRock(i)).c_str(), _black)) ||
	      !(texture = SDL_CreateTextureFromSurface(_renderer.get(), text)))
	    continue;
	  src.x = 0;
	  src.y = 0;
	  src.w = text->w;
	  src.h = text->h;
	  dest.x = x[i];
	  dest.y = y[i];
	  dest.w = text->w > 60 ? 60 : text->w;
	  dest.h = text->h;
	  SDL_FreeSurface(text);
	  _renderer.renderCopy(texture, src, dest);
	  SDL_DestroyTexture(texture);
	}
      SDL_Surface		*text;

      if (&(text = TTF_RenderText_Blended(_font, std::string("id : " + std::to_string(_id)).c_str(), _black)) && (texture = SDL_CreateTextureFromSurface(_renderer.get(), text)))
	{
	  src.w = text->w;
	  src.h= text->h;
	  dest.x = 50;
	  dest.y = y[5] + 40;
	  dest.w = text->w;
	  dest.h = 40;
	  SDL_FreeSurface(text);
	  _renderer.renderCopy(texture, src, dest);
	  SDL_DestroyTexture(texture);
	  if (&(text = TTF_RenderText_Blended(_font, c->getName().c_str(), _black)) && (texture = SDL_CreateTextureFromSurface(_renderer.get(), text)))
	    {
	      src.w = text->w;
	      src.h= text->h;
	      dest.x = 50;
	      dest.y = 10;
	      dest.w = text->w > 300 ? 300 : text->w;
	      dest.h = 40;
	      SDL_FreeSurface(text);
	      _renderer.renderCopy(texture, src, dest);
	      SDL_DestroyTexture(texture);

	      if ((texture = cmgr.getFace(c->getLvl())))
		{
		  src.w = 36;
		  src.h = 36;
		  src.x = 0;
		  src.y = 0;
		  dest.x = x[7];
		  dest.y = y[7];
		  dest.w = 36;
		  dest.h = 36;
		  _renderer.renderCopy(texture, src, dest);
		}
	    }
	}
    }
  _renderer.renderPresent();
  return (0);
}

  int		Inventory::update(int id)
{
  if (!_loaded)
    return (-1);
  _id = id;
  return (0);
}
