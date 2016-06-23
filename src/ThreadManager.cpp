//
// ThreadManager.cpp for indieStudio in /home/wilmot_g/Rendu/cpp_indie_studio
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun May 29 02:58:44 2016 guillaume wilmot
// Last update Thu Jun 23 15:27:30 2016 guillaume wilmot
//

#include <iostream>
#include "ScopedLock.hpp"
#include "ThreadManager.hpp"

void		ThreadManager::addThread(std::thread *thread)
{
  ScopedLock	lock(_threads._mutex);

  _threads._var.push_back(thread);
}

ThreadManager	&ThreadManager::operator<<(std::thread *thread)
{
  addThread(thread);
  return (*this);
}

void		ThreadManager::end()
{
  ScopedLock	lock(_threads._mutex);

  while (_threads._var.size())
    {
      if (_threads._var[0])
	{
	  _threads._var[0]->join();
	  delete _threads._var[0];
	}
      _threads._var.erase(_threads._var.begin());
    }
  _threads._var.clear();
}
