/*
** main.c for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Jun  7 16:01:13 2016 guillaume wilmot
// Last update Thu Jun 23 10:13:34 2016 guillaume wilmot
*/

#include <iostream>
#include <thread>
#include <unistd.h>
#include "SDL.h"
#include "Displayer.hpp"

#define PURPLE	"\033[01;35m"
#define END	"\033[0m"

void			help()
{
  std::cout << "Use your " << PURPLE << "Wheel" << END << " or " << PURPLE << "Touchpad" << END;
  std::cout << " to zoom or dezoom" << std::endl;
  std::cout << "Use the " << PURPLE << "Arrow Keys" << END << " to move around the map" << std::endl;
  std::cout << "Press " << PURPLE << "C" << END << " to retrieve the window" << std::endl;
  std::cout << "Press " << PURPLE << "MAJ + C" << END << " to recenter the map" << std::endl;
  std::cout << "Press " << PURPLE << "ESC" << END << " to quit" << std::endl;
  std::cout << "Enjoy !" << std::endl;
}

void			create(bool *stop)
{
  std::string		tmp;
  fd_set		readf;
  struct timeval	tv;

  while (!Displayer::get() && !(*stop))
    usleep(100000);
  while (!(*stop))
    {
      tv.tv_sec = 0;
      tv.tv_usec = 100000;
      FD_ZERO(&readf);
      FD_SET(0, &readf);
      if (select(1, &readf, NULL, NULL, &tv) == -1)
	return ;
      if (FD_ISSET(0, &readf))
	while (std::getline(std::cin, tmp))
	  if (Displayer::get()->execute(tmp) == -1)
	    std::cerr << "Command not found" << std::endl;
	  else
	    std::cout << "Ok" << std::endl;
    }
  return ;
}

int			main()
{
  std::thread		*displayer;
  std::thread		*client;
  bool			stop = false;

  help();
  displayer = new std::thread(Displayer::create);
  client = new std::thread(create, &stop);
  displayer->join();
  stop = true;
  client->join();
}
