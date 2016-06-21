//
// Charset.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 16:27:45 2016 guillaume wilmot
// Last update Tue Jun 21 15:00:46 2016 guillaume wilmot
//

#include <iostream>
#include "Charset.hh"
#include "SDL2/SDL_image.h"

Charset::Charset()
{
  _texture = NULL;
  _lvl = 0;
  _w = 0;
  _h = 0;
  _posX = 0;
  _posY = 0;
  _dir = UP;
  _anim = WALK;
  _frame = 0;
  _speed = 4;
  _timer = 0;
  _status = true;
}

Charset::Charset(const Charset &) {}
Charset::~Charset() {}

Charset		&Charset::operator=(const Charset &) {return (*this);}

void		Charset::render(ZBuffer &zbuff, CharacterManager &mgr)
{
  SDL_Rect	src;
  SDL_Rect	pos;
  TextureManager::surface s;

  if (!(_texture = mgr[_lvl][_anim]))
    return ;
  SDL_QueryTexture(_texture, NULL, NULL, &_w, &_h);
  _w /= mgr.getWidth(_lvl, 1 * _anim);
  _h /= mgr.getHeight(_lvl, 1 * _anim);

  src.x = 1.0 * (_frame % mgr.getWidth(_lvl, 1 * _anim)) * _w;
  src.y = 1.0 * (static_cast<int>(_dir) % mgr.getHeight(_lvl, 1 * _anim)) * _h;
  src.w = _w;
  src.h = _h;
  pos.x = _posX;
  pos.y = _posY;
  pos.w = _w;
  pos.h = _h;
  s.surface = NULL;
  s.texture = _texture;
  zbuff.add(s, &src, &pos, 2);

  if (_status && _timer++ == _speed)
    {
      _frame = (_frame + 1) % mgr.getWidth(_lvl, 1 * _anim);
      _timer = 0;
    }

  /**/
  static int i = 0;
  if (i++ == 30)
    {
      i = 0;
      _dir = static_cast<Direction>(_dir + 1);
      if (_dir == 4)
	{
	  _dir = static_cast<Direction>(0);
	  _anim = static_cast<Anim>(_anim + 1);
	  if (_anim == 3)
	    {
	      _anim = static_cast<Anim>(0);
	      _lvl = (_lvl + 1) % 8;
	    }
	}
    }
  /**/
}

void		Charset::done()
{
  _status = 0;
  _frame = 0;
}

Direction	Charset::getDirection()		const	{return (_dir);}
Anim		Charset::getAnim()		const	{return (_anim);}
bool		Charset::getStatus()		const	{return (_status);}
int		Charset::getSpeed()		const	{return (_speed);}
int		Charset::getFrame()		const	{return (_frame);}
int		Charset::getPosX()		const	{return (_posX);}
int		Charset::getPosY()		const	{return (_posY);}
void		Charset::setDirection(Direction s)	{_dir = s;}
void		Charset::setAnim(Anim s)		{_anim = s;}
void		Charset::setStatus(bool s)		{_status = s;}
void		Charset::setSpeed(int s)		{_speed = s;}
void		Charset::setPosX(int s)			{_posX = s;}
void		Charset::setPosY(int s)			{_posY = s;}
void		Charset::setFrame(int s)		{_frame = s;}
