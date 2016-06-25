//
// Charset.hh for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 17:32:15 2016 guillaume wilmot
// Last update Sat Jun 25 22:42:49 2016 guillaume wilmot
//

#ifndef CHARSET_HH_
# define CHARSET_HH_

# include <string>
# include "ZBuffer.hpp"
# include "SDL.h"

enum		Direction
  {
    LEFT = 1,
    DOWN,
    RIGHT,
    UP,
  };

enum		Anim
  {
    STAND = 0,
    WALK,
    DIE,
  };

class		Charset {
public:
  Charset();
  ~Charset();

  int			render(ZBuffer &, CharacterManager &, int);

  Direction		getDirection() const;
  Anim			getAnim() const;
  int			getSpeed() const;
  int			getFrame() const;
  int			getPosX() const;
  int			getPosY() const;
  void			setLvl(int);
  void			setDirection(Direction);
  void			setAnim(Anim);
  void			setSpeed(int);
  void			setPosX(int);
  void			setPosY(int);
  void			setOldPosX(int);
  void			setOldPosY(int);
  void			setFrame(int);
  void			setTeam(const std::string &);
  void			setInv(int *);
  void			kill();

private:
  Charset(const Charset &);
  Charset	&operator=(const Charset &);

  SDL_Texture   *_texture;

  int		_lvl;
  Direction	_dir;
  Anim		_anim;

  bool		_dead;
  int           _w;
  int           _h;
  int		_posX;
  int		_posY;
  int		_oldPosX;
  int		_oldPosY;
  int           _frame;

  bool		_move;
  int		_movement;
  int		_time;
  int		_speed;
  int		_timer;

  int		_inv[7];

  std::string	_team;
};

#endif /* !CHARSET_HH_ */
