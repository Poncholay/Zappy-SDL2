//
// ZBuffer.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 13 16:47:59 2016 guillaume wilmot
// Last update Sat Jun 25 21:35:15 2016 guillaume wilmot
//

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "ZBuffer.hpp"

ZBuffer::ZBuffer(int x, int y)
{
  _x = 0;
  _y = 0;
  if (!(_surface = SDL_CreateRGBSurface(0, x, y, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF)))
    throw std::exception();
}

ZBuffer::~ZBuffer()
{
  if (_surface)
    SDL_FreeSurface(_surface);
}

ZBuffer::ZBuffer(const ZBuffer &s)
{
  _surface = s.getSurface();
  _buffer = s.getBuffer();
}

ZBuffer		&ZBuffer::operator=(const ZBuffer &s)
{
  if (&s != this)
    {
      _surface = s.getSurface();
      _buffer = s.getBuffer();
    }
  return (*this);
}

void		ZBuffer::add(TextureManager::surface &t, SDL_Rect *in, SDL_Rect *out, int layer)
{
  ZBuffer::buff	b;

  if (!_buffer.size())
    SDL_FillRect(_surface, NULL, SDL_MapRGBA(_surface->format, 0, 0, 0, 0));
  memset(&b, 0, sizeof(b));
  b.layer = layer;
  b.surface = t;
  if (t.surface)
    {
      b.out.h = t.surface->h;
      b.out.w = t.surface->w;
      b.in.h = t.surface->h;
      b.in.w = t.surface->w;
    }
  if (in)
    b.in = *in;
  if (out)
    b.out = *out;
  b.out.y += 64;
  b.out.y += _y;
  b.out.x += _x;
  _buffer.push_back(b);
}

SDL_Surface	*ZBuffer::renderToSurface()
{
  std::sort(_buffer.begin(), _buffer.end(), sort);
  for (unsigned int i = 0; i < _buffer.size(); i++)
    if (_buffer[i].surface.surface)
      SDL_BlitSurface(_buffer[i].surface.surface, &_buffer[i].in, _surface, &_buffer[i].out);
  _buffer.clear();
  return (_surface);
}

void		ZBuffer::render()
{
  std::sort(_buffer.begin(), _buffer.end(), sort);
  for (unsigned int i = 0; i < _buffer.size(); i++)
    if (_buffer[i].surface.texture)
      SDL_RenderCopy(_renderer->get(), _buffer[i].surface.texture, &_buffer[i].in, &_buffer[i].out);
  _buffer.clear();
}

bool		sort(ZBuffer::buff a, ZBuffer::buff b)
{
  return (a.layer < b.layer || (a.out.y + a.out.h < b.out.y + b.out.h && a.layer <= b.layer));
}
