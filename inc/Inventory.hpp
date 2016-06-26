//
// Inventory.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 26 15:44:38 2016 guillaume wilmot
// Last update Sun Jun 26 19:42:25 2016 guillaume wilmot
//

#ifndef INVENTORY_HPP_
# define INVENTORY_HPP_

# include <map>
# include "SDL.h"
# include "SDL_ttf.h"
# include "Charset.hh"
# include "Renderer.hpp"
# include "CharacterManager.hpp"

class		Inventory {
public:
  Inventory();
  ~Inventory();

  int		init();
  int		render(std::map<int, Charset *> &, CharacterManager &);
  int		update(int);

  private:

  Inventory(const Inventory &) {}
  Inventory	&operator=(const Inventory &) {return (*this);}

  bool		_loaded;
  SDL_Rect	_dims;
  Renderer	_renderer;
  int		_id;
  SDL_Window	*_win;
  SDL_Texture	*_back;
  TTF_Font	*_font;
  SDL_Color	_black;
};

#endif /* !INVENTORY_HPP_ */
