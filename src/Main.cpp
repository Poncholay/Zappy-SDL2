/*
** main.c for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Jun  7 16:01:13 2016 guillaume wilmot
// Last update Sun Jun 26 22:41:36 2016 guillaume wilmot
*/

#include <iostream>
#include <thread>
#include "Displayer.hpp"
#include "ThreadManager.hpp"
#include "Client.hpp"
#include "Sounds.hpp"

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

int			main(int argc, char **argv)
{
  bool			stop = false;
  bool			start = false;

  if (argc < 3)
    return (std::cerr << argv[0] << ": host port" << std::endl, -1);
  help();
  ThreadManager::get() << (new std::thread(Displayer::create, std::ref(stop), std::ref(start)));
  ThreadManager::get() << (new std::thread(Client::create, std::ref(stop), std::ref(start), argv[1], std::atoi(argv[2])));
  ThreadManager::get().end();
}
