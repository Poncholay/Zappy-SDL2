//
// CharacterManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Jun 20 13:06:52 2016 guillaume wilmot
// Last update Tue Jun 21 00:07:29 2016 guillaume wilmot
//

#ifndef CHARSETMANAGER_HPP_
# define CHARSETMANAGER_HPP_

# define LVLMAX 8
# define NBANIM 3

# include <vector>
# include "Renderer.hpp"
# include "SDL.h"

class		CharacterManager {
public:
  CharacterManager();
  ~CharacterManager();

  void				destroy();
  void				setRenderer(Renderer *r) {_r = r;}
  int				init(int, Renderer *);
  int				getHeight(unsigned int, unsigned int) const;
  int				getWidth(unsigned int, unsigned int) const;

  std::vector<SDL_Texture *>	&operator[](int i)	{return (_vector[i]);}

private:
  CharacterManager(const CharacterManager &)		{}
  CharacterManager&operator=(const CharacterManager &)	{return (*this);}

  std::vector<std::vector<SDL_Texture *> >		_vector;
  unsigned int						_n;
  unsigned int						_a;
  int							_scale;
  Renderer						*_r;
};

#endif /* !CHARSETMANAGER_HPP_ */
