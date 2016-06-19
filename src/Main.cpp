/*
** main.c for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Jun  7 16:01:13 2016 guillaume wilmot
// Last update Sun Jun 19 22:36:43 2016 guillaume wilmot
*/

#include <iostream>
#include <thread>
#include "SDL.h"
#include "Displayer.hpp"

int		check(int argc, char **argv)
{
  if (argc < 3)
    return (std::cerr << "./zappy_gdx width height" << std::endl, -1);
  if (SDL_VideoInit(NULL) == -1)
    return (std::cerr << "Could not initialize SDL video." << std::endl, -1);
  if (std::atoi(argv[1]) > 100 || std::atoi(argv[2]) > 100)
    return (std::cerr << "Map is too big." << std::endl, -1);
  return (0);
}

int		main(int argc, char **argv)
{
  if (check(argc, argv) == -1)
    return (-1);

  std::thread	*d;
  d = new std::thread(Displayer::create);
  d->join();
}
