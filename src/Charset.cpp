//
// Charset.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 16:27:45 2016 guillaume wilmot
// Last update Sat Jun 25 23:01:45 2016 guillaume wilmot
//

#include <iostream>
#include <cmath>
#include "Charset.hh"
#include "SDL2/SDL_image.h"
#include "Scale.hpp"
#include "Time.hpp"

Charset::Charset()
{
  _texture = NULL;
  _lvl = 0;
  _w = 0;
  _h = 0;
  _posX = 0;
  _posY = 0;
  _oldPosX = 0;
  _oldPosY = 0;
  _dir = UP;
  _anim = WALK;
  _frame = 0;
  _move = 0;
  _speed = 1;
  _timer = 0;
  _dead = false;
  _movement = 0;
}

Charset::Charset(const Charset &) {}
Charset::~Charset() {}

Charset		&Charset::operator=(const Charset &) {return (*this);}

int		Charset::render(ZBuffer &zbuff, CharacterManager &mgr, int width)
{
  SDL_Rect	src;
  SDL_Rect	pos;
  TextureManager::surface s;
  float		percentX = Scale::get()._x * 1.5;
  float		percentY = Scale::get()._y * 1.5;

  if (!(_texture = mgr[_lvl][_anim % 3]))
    return (-1);
  SDL_QueryTexture(_texture, NULL, NULL, &_w, &_h);
  _w /= mgr.getWidth(_lvl, 1 * _anim);
  _h /= mgr.getHeight(_lvl, 1 * _anim);

  src.x = 1.0 * (_frame % mgr.getWidth(_lvl, 1 * _anim)) * _w;
  src.y = 1.0 * ((static_cast<int>(_dir) - 1) % mgr.getHeight(_lvl, 1 * _anim)) * _h;
  src.w = _w;
  src.h = _h;

  pos.w = _w * percentX;
  pos.h = _h * percentY;

  double	percent = 1;

  if (_move)
    percent = 1.0 * _movement / _time;

  pos.x = (_oldPosX + _oldPosY) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 4 +
    ((1.0 * pos.w) / 2);
  pos.y = (width - (_oldPosY + 1) + _oldPosX) * 1.0 * Scale::get()._h / 4 - ((1.0 * pos.h) / 2);

  if (_move)
    {
      pos.x -= (((_oldPosX + _oldPosY) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 4) -
		((_posX + _posY) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 4)) * percent;
      pos.y -= (((width - (_oldPosY + 1) + _oldPosX) * 1.0 * Scale::get()._h / 4) -
		((width - (_posY + 1) + _posX) * 1.0 * Scale::get()._h / 4)) * percent;
    }

  s.surface = NULL;
  s.texture = _texture;
  zbuff.add(s, &src, &pos, 2);

  if (_timer++ == _speed)
    {
      if (_dead)
	if (_frame + 1 == mgr.getWidth(_lvl, 1 * _anim))
	  return (-1);
      _frame = (_frame + 1) % mgr.getWidth(_lvl, 1 * _anim);
      _timer = 0;
      if (_move)
	if (_movement++ == _time)
	  {
	    _oldPosX = _posX;
	    _oldPosY = _posY;
	    _move = 0;
	    _anim = STAND;
	  }
    }
  return (0);
}

Direction	Charset::getDirection()		const	{return (_dir);}
Anim		Charset::getAnim()		const	{return (_anim);}
int		Charset::getSpeed()		const	{return (_speed);}
int		Charset::getFrame()		const	{return (_frame);}
int		Charset::getPosX()		const	{return (_posX);}
int		Charset::getPosY()		const	{return (_posY);}
void		Charset::setLvl(int s)			{_lvl = s; _frame = 0;}
void		Charset::setDirection(Direction s)	{_dir = s; _frame = 0;}
void		Charset::setAnim(Anim s)		{_anim = s; _frame = 0;}
void		Charset::setSpeed(int s)		{_speed = s;}
void		Charset::setFrame(int s)		{_frame = s;}
void		Charset::setTeam(const std::string &s)	{_team = s;}
void		Charset::setInv(int *s)			{for (int i = 0; i < 7; i++) _inv[i] = s[i];}
void		Charset::kill()				{_dead = true; _anim = DIE; _frame = 0;}

void		Charset::setOldPosX(int s)		{_oldPosX = s;}
void		Charset::setOldPosY(int s)		{_oldPosY = s;}

void		Charset::setPosX(int s)
{
  if (s < 0)
    return ;
  _oldPosX = _posX;
  _posX = s;
  _movement = 0;
  _move = 1;
  double time;
  Time::get() >> time;
  _time = time * 60 * (7 / _speed);
  _anim = WALK;
}

void		Charset::setPosY(int s)
{
  if (s < 0)
    return ;
  _oldPosY = _posY;
  _posY = s;
  _movement = 0;
  _move = 1;
  double time;
  Time::get() >> time;
  _time = time * 60 * (7 / _speed);
  _anim = WALK;
}
