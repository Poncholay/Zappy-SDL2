//
// Displayer.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:23:17 2016 guillaume wilmot
// Last update Thu Jun 23 10:11:15 2016 guillaume wilmot
//

#ifndef DISPLAYER_HPP_
# define DISPLAYER_HPP_

# include "SDL.h"
# include "ScopedLock.hpp"
# include "Mutex.hpp"
# include "ShapedWindow.hpp"
# include "ZBuffer.hpp"
# include "TextureManager.hpp"
# include "Map.hpp"
# include "Charset.hh"

class		Displayer {
public:
  Displayer();
  ~Displayer()								{}

  static void		create();
  static Displayer	*get(Displayer *d = NULL, bool o = false)
  {
    static Mutex	mutex;
    ScopedLock		lock(mutex);
    static Displayer	*dis = NULL;
    if (o || d)
      dis = d;
    return (dis);
  }

  int			start();
  int			execute(const std::string &);

private:
  Displayer(const Displayer &) : _win("Zappy"), _zbuff(WINX, WINY)	{}
  Displayer		&operator=(const Displayer &)			{return (*this);}

  //PROTOCOL
  int			msz(std::istringstream &);
  int			bct(std::istringstream &);
  int			tna(std::istringstream &);
  int			pnw(std::istringstream &);
  int			ppo(std::istringstream &);
  int			plv(std::istringstream &);
  int			pin(std::istringstream &);
  int			pex(std::istringstream &);
  int			pbc(std::istringstream &);
  int			pic(std::istringstream &);
  int			pie(std::istringstream &);
  int			pfk(std::istringstream &);
  int			pdr(std::istringstream &);
  int			pgt(std::istringstream &);
  int			pdi(std::istringstream &);
  int			enw(std::istringstream &);
  int			eht(std::istringstream &);
  int			ebo(std::istringstream &);
  int			edi(std::istringstream &);
  int			sgt(std::istringstream &);
  int			seg(std::istringstream &);
  int			smg(std::istringstream &);
  int			suc(std::istringstream &);
  int			sbp(std::istringstream &);

  Mutex			_mutex;
  ShapedWindow		_win;
  ZBuffer		_zbuff;
  TextureManager	_tmgr;
  TextureManager	_tmgrChar;
  Map			_map;

  int			_time;
  bool			_end;

  std::vector<std::string>						_teams;
  std::map<int, Charset *>						_players;
  // std::map<int, Eggs *>							_eggs;
  std::map<std::string, int (Displayer::*)(std::istringstream &)>	_ptrMtd;
};

#endif /* !DISPLAYER */
