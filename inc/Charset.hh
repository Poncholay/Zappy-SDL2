//
// Charset.hh for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 17:32:15 2016 guillaume wilmot
// Last update Sun Jun 19 12:53:33 2016 guillaume wilmot
//

#ifndef CHARSET_HH_
# define CHARSET_HH_

# include <string>
# include "SDL.h"

enum		Direction
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
  };

enum		Anim
  {
    STAND = 0,
    WALK,
    DIE,
  };

class		Charset {
public:
  Charset(SDL_Renderer *, const std::string &);
  ~Charset();

  int			load(int, int);
  void			render();
  void			done();

  Direction		getDirection() const;
  Anim			getAnim() const;
  bool			getStatus() const;
  int			getSpeed() const;
  int			getFrame() const;
  int			getPosX() const;
  int			getPosY() const;
  void			setDirection(Direction);
  void			setAnim(Anim);
  void			setStatus(bool);
  void			setSpeed(int);
  void			setPosX(int);
  void			setPosY(int);
  void			setFrame(int);
private:
  Charset(const Charset &);
  Charset	&operator=(const Charset &);

  SDL_Surface   *_charset;
  SDL_Texture   *_texture;
  SDL_Renderer	*_renderer;
  std::string   _name;
  Direction	_dir;
  Anim		_anim;
  int           _nbx;
  int           _nby;
  int           _w;
  int           _h;
  int		_posX;
  int		_posY;
  int           _frame;
  int		_speed;
  int		_timer;
  bool		_status;
  bool          _loaded;
};

#endif /* !CHARSET_HH_ */
