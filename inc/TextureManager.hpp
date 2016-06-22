//
// TextureManager.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 12 18:53:10 2016 guillaume wilmot
// Last update Wed Jun 22 22:33:17 2016 guillaume wilmot
//

#ifndef TEXTUREMANAGER_HPP_
# define TEXTUREMANAGER_HPP_

# include <map>
# include <vector>
# include "Renderer.hpp"
# include "ScopedPtr.hpp"
# include "CharacterManager.hpp"
# include "SDL.h"

class		CharsetManager;

class		TextureManager {
public:
  TextureManager() {_scale = -1; _r = NULL;}
  ~TextureManager();

  typedef struct	Surface {
    SDL_Surface		*surface;
    SDL_Texture		*texture;
  }			surface;

  int			init(int);
  void			setRenderer(Renderer *r)		{_r = r;}
  void			destroy();
  int			add(const std::string &, const std::string &, float = 0, float = 0, int = 0, bool = false);
  int			add(const std::string &, SDL_Surface *);
  int			update();
  static SDL_Surface	*resize(SDL_Surface *, float, float, int, bool = false);

  CharacterManager	&getCmgr()				{return (_cmgr);}

  std::vector<surface>	&getV(const std::string &);
  surface		&get(const std::string &, int = -1);
  surface		&operator[](const std::string &);

private:
  TextureManager(const TextureManager &) {}
  TextureManager	&operator=(const TextureManager &)	{return (*this);}

  std::map<std::string, std::vector<surface> >			_map;
  int								_scale;
  Renderer							*_r;
  CharacterManager						_cmgr;
};

#endif /* !TEXTUREMANAGER_HPP_ */
