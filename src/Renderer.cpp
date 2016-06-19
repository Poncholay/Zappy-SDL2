//
// Renderere.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 16:04:05 2016 guillaume wilmot
// Last update Sun Jun 19 16:19:01 2016 guillaume wilmot
//

#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer(SDL_Window *w)
{
  if (!w || !(_renderer = SDL_CreateRenderer(w, -1, 0)))
    {
      std::cerr << "Could not create renderer." << std::endl;
      throw std::bad_alloc();
    }
}

Renderer::~Renderer()
{
  if (_renderer)
    SDL_DestroyRenderer(_renderer);
}

int		Renderer::init(SDL_Window *w)
{
  if (!w || !(_renderer = SDL_CreateRenderer(w, -1, 0)))
    return (std::cerr << "Could not create renderer." << std::endl, -1);
  return (0);
}

int		Renderer::setRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  return (!_renderer ? -1 : SDL_SetRenderDrawColor(_renderer, r, g, b, a));
}

int		Renderer::renderClear()
{
  return (!_renderer ? -1 : SDL_RenderClear(_renderer));
}

int		Renderer::renderCopy(SDL_Texture *t, SDL_Rect f, SDL_Rect to)
{
  return (!_renderer ? -1 : SDL_RenderCopy(_renderer, t, &f, &to));
}

void		Renderer::renderPresent()
{
  if (_renderer)
    SDL_RenderPresent(_renderer);
}
