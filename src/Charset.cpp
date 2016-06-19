//
// Charset.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 16:27:45 2016 guillaume wilmot
// Last update Sun Jun 19 23:43:32 2016 guillaume wilmot
//

#include <iostream>
#include "Charset.hh"
#include "SDL2/SDL_image.h"

Charset::Charset(const std::string &name)
{
  _charset = NULL;
  _texture = NULL;
  _name = name;
  _nbx = 0;
  _nby = 0;
  _w = 0;
  _h = 0;
  _posX = 0;
  _posY = 0;
  _dir = UP;
  _anim = STAND;
  _frame = 0;
  _speed = 15;
  _timer = 0;
  _status = true;
  _loaded = false;
}

Charset::~Charset() {if (_loaded) SDL_FreeSurface(_charset);}

int		Charset::load(int nbx, int nby, Renderer &renderer)
{
  if (!(_charset = IMG_Load(_name.c_str())))
    return (std::cerr << "Could not load " << _name << std::endl, -1);
  if (!(_texture = SDL_CreateTextureFromSurface(renderer.get(), _charset)))
    return (std::cerr << "Could not create Texture" << std::endl, -1);
  _nbx = nbx;
  _nby = nby;
  _nbx = _nbx;
  _nby = _nby;
  _w = _charset->w / _nbx;
  _h = _charset->h / _nby;
  _loaded = true;
  return (0);
}

void		Charset::render(ZBuffer &zbuff)
{
  SDL_Rect	src;
  SDL_Rect	pos;
  TextureManager::surface s;
  static int	i = 0;

  src.x = (_frame % _nbx) * _w;
  src.y = (static_cast<int>(_dir) % _nby // + static_cast<int>(_anim) % _nby
	   ) * _h;
  src.w = _w;
  src.h = _h;
  pos.x = _posX;
  pos.y = _posY;
  pos.w = _w;
  pos.h = _h;

  s.surface = NULL;
  s.texture = _texture;
  zbuff.add(s, &src, &pos);

  if (_status && _timer++ == _speed)
    {
      _frame = (_frame + 1) % _nbx;
      _timer = 0;
      if (i++ == 15)
	{
	  setDirection(static_cast<Direction>((getDirection() + 1) % _nby));
	  i = 0;
	}
    }
}

void		Charset::done()
{
  _status = 0;
  _frame = 0;
}

Direction	Charset::getDirection() const {return (_dir);}
Anim		Charset::getAnim() const {return (_anim);}
bool		Charset::getStatus() const {return (_status);}
int		Charset::getSpeed() const {return (_speed);}
int		Charset::getFrame() const {return (_frame);}
int		Charset::getPosX() const {return (_posX);}
int		Charset::getPosY() const {return (_posY);}
void		Charset::setDirection(Direction s) {_dir = s;}
void		Charset::setAnim(Anim s) {_anim = s;}
void		Charset::setStatus(bool s) {_status = s;}
void		Charset::setSpeed(int s) {_speed = s;}
void		Charset::setPosX(int s) {_posX = s;}
void		Charset::setPosY(int s) {_posY = s;}
void		Charset::setFrame(int s) {_frame = s;}
