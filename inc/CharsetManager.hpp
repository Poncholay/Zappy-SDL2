//
// CharsetManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 20 13:06:52 2016 guillaume wilmot
// Last update Mon Jun 20 15:39:34 2016 guillaume wilmot
//

#ifndef CHARSETMANAGER_HPP_
# define CHARSETMANAGER_HPP_

# define LVLMAX 8
# define NBANIM 3

# include <vector>
# include "SDL.h"

class		CharsetManager {
public:
  CharsetManager(int = LVLMAX, int = NBANIM);
  ~CharsetManager();

  int				init(int);
  std::vector<SDL_Texture *>	&operator[](int i)	{return (_vector[i]);}

private:
  CharsetManager(const CharsetManager &)		{}
  CharsetManager&operator=(const CharsetManager &)	{return (*this);}

  std::vector<std::vector<SDL_Texture *> >			_vector;
  unsigned int							_n;
  unsigned int							_a;
};

#endif /* !CHARSETMANAGER_HPP_ */
