/*
** main.c for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Jun  7 16:01:13 2016 guillaume wilmot
// Last update Fri Jun 24 21:24:30 2016 guillaume wilmot
*/

#include <iostream>
#include <thread>
#include <unistd.h>
#include "SDL.h"
#include "Displayer.hpp"
#include "ThreadManager.hpp"

#define PURPLE	"\033[01;35m"
#define RED	"\033[01;31m"
#define VERT	"\033[01;32m"
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

void			create(bool &stop, bool &start)
{
  std::string		tmp;
  fd_set		readf;
  struct timeval	tv;

  while (!Displayer::get() || !start)
    {
      if (stop)
	return ;
      usleep(100000);
    }
  while (!stop)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 100000;
      FD_ZERO(&readf);
      FD_SET(0, &readf);
      if (select(1, &readf, NULL, NULL, &tv) == -1)
	return ;
      if (FD_ISSET(0, &readf))
	{
	  if (std::getline(std::cin, tmp))
	    {
	      std::cerr << tmp << " : ";
	      if (Displayer::get())
		std::cerr << (Displayer::get()->execute(tmp) == -1 ?
			      std::string(RED) + "Command not found" + std::string(END) :
			      std::string(VERT) + "Ok" + std::string(END)) << std::endl;
	    }
	  else if (std::cin.eof())
	    {
	      if (isatty(0))
		stop = true;
	      return ;
	    }
	}
    }
}

int			main()
{
  bool			stop = false;
  bool			start = false;

  help();
  ThreadManager::get() << (new std::thread(Displayer::create, std::ref(stop), std::ref(start)));
  ThreadManager::get() << (new std::thread(create, std::ref(stop), std::ref(start)));
  ThreadManager::get().end();
}
