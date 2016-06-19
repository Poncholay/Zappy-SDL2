//
// SDL.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 16:35:38 2016 guillaume wilmot
// Last update Fri Jun 10 16:35:54 2016 guillaume wilmot
//

SDL::SDL()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  if ((_window = SDL_CreateWindow("", 0, 0, WINX, WINY, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS)) == NULL)
    throw std::exception();
  if ((_screen = SDL_GetWindowSurface(_window)) == NULL)
    throw std::exception();
  if ((_renderer =  SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
    throw std::exception();
  if (TTF_Init() == -1)
    throw std::exception();
  _assets = new SDL::Assets(_renderer);
  _dragging = false;
  _it = 0;
}
