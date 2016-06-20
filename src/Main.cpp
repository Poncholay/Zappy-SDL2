/*
** main.c for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Jun  7 16:01:13 2016 guillaume wilmot
// Last update Mon Jun 20 22:07:53 2016 guillaume wilmot
*/

#include <iostream>
#include <thread>
#include "SDL.h"
#include "Displayer.hpp"

#define PURPLE	"\033[01;35m"
#define END	"\033[0m"

void		help()
{
  std::cout << "Use your " << PURPLE << "Wheel" << END << " or " << PURPLE << "Touchpad" << END;
  std::cout << " to zoom or dezoom" << std::endl;
  std::cout << "Use the " << PURPLE << "Arrow Keys" << END << " to move around the map" << std::endl;
  std::cout << "Press " << PURPLE << "C" << END << " to retrieve the window" << std::endl;
  std::cout << "Press " << PURPLE << "MAJ + C" << END << " to recenter the map" << std::endl;
  std::cout << "Press " << PURPLE << "ESC" << END << " to quit" << std::endl;
  std::cout << "Enjoy !" << std::endl;
}

int		main()
{
  std::thread	*displayer;
  // std::thread	*client;

  help();
  // client = new std::thread(ZClient::create);
  displayer = new std::thread(Displayer::create);
  displayer->join();
}
