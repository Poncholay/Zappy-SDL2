//
// TextureManager.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 12 18:53:10 2016 guillaume wilmot
// Last update Sun Jun 19 16:27:47 2016 guillaume wilmot
//

#ifndef TEXTUREMANAGER_HPP_
# define TEXTUREMANAGER_HPP_

# include <map>
# include <vector>
# include "Renderer.hpp"
# include "ScopedPtr.hpp"
# include "SDL.h"

class		TextureManager {
public:
  TextureManager() {_scale = -1; _r = NULL;}
  ~TextureManager();

  typedef struct	Surface {
    SDL_Surface		*surface;
    SDL_Texture		*texture;
  }			surface;

  void			setRenderer(Renderer *r)		{_r = r;}
  void			destroy();
  int			init(int);
  int			add(const std::string &, const std::string &, float = 0, float = 0, int = 0);
  int			add(const std::string &, SDL_Surface *);
  int			update();
  SDL_Surface		*resize(SDL_Surface *, float, float, int) const;

  std::vector<surface>	&getV(const std::string &);
  surface		&get(const std::string &);
  surface		&operator[](const std::string &);

private:
  TextureManager(const TextureManager &) {}
  TextureManager	&operator=(const TextureManager &)	{return (*this);}

  std::map<std::string, std::vector<surface> >		_map;
  std::vector<surface *>				_free;
  int							_scale;
  Renderer						*_r;
};

#endif /* !TEXTUREMANAGER_HPP_ */
