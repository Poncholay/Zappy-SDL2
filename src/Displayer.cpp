//
// Displayer.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:30:55 2016 guillaume wilmot
// Last update Thu Jun 23 22:52:29 2016 guillaume wilmot
//

#include <algorithm>
#include <sstream>
#include <string>
#include <unistd.h>
#include "ScopedLock.hpp"
#include "FpsManager.hpp"
#include "Displayer.hpp"
#include "Charset.hh"

Displayer::Displayer() : _win("Zappy", 0, 0), _zbuff(WINX, WINY)
{
  _ptrMtd["msz"] = &Displayer::msz;
  _ptrMtd["bct"] = &Displayer::bct;
  _ptrMtd["tna"] = &Displayer::tna;
  _ptrMtd["pnw"] = &Displayer::pnw;
  _ptrMtd["ppo"] = &Displayer::ppo;
  _ptrMtd["plv"] = &Displayer::plv;
  _ptrMtd["pin"] = &Displayer::pin;
  _ptrMtd["pex"] = &Displayer::pex;
  _ptrMtd["pbc"] = &Displayer::pbc;
  _ptrMtd["pic"] = &Displayer::pic;
  _ptrMtd["pie"] = &Displayer::pie;
  _ptrMtd["pfk"] = &Displayer::pfk;
  _ptrMtd["pdr"] = &Displayer::pdr;
  _ptrMtd["pgt"] = &Displayer::pgt;
  _ptrMtd["pdi"] = &Displayer::pdi;
  _ptrMtd["enw"] = &Displayer::enw;
  _ptrMtd["eht"] = &Displayer::eht;
  _ptrMtd["ebo"] = &Displayer::ebo;
  _ptrMtd["edi"] = &Displayer::edi;
  _ptrMtd["sgt"] = &Displayer::sgt;
  _ptrMtd["seg"] = &Displayer::seg;
  _ptrMtd["smg"] = &Displayer::smg;
  _ptrMtd["suc"] = &Displayer::suc;
  _ptrMtd["sbp"] = &Displayer::sbp;
  _time = 0;
  _end = false;
}

void			Displayer::create(bool &stop, bool &start)
{
  Displayer		d;

  Displayer::get(&d);
  if (SDL_VideoInit(NULL) == -1)
    {
      std::cerr << "Could not initialize SDL video." << std::endl;
      return ;
    }
  d.start(stop, start);
  Displayer::get(NULL, true);
  SDL_VideoQuit();
}

int			Displayer::start(bool &stop, bool &start)
{
  FpsManager		fpsMgr;
  SDL_Event		ev;
  SDL_Rect		dims;

  _win.setTmgr(&_tmgr);
  _win.setZbuff(&_zbuff);
  while ((_win.getHeight() == 0 || _win.getWidth() == 0) && !stop)
    {
      start = true;
      usleep(100000);
    }
  _win.getRenderer().setRenderDrawColor(0, 0, 0, 0);

  /**/
  Charset            C;
  C.setPosY(300);
  C.setPosX(300);
  /**/

  while (!stop)
    {
      fpsMgr.apply();

      _mutex.lock();
      while (SDL_PollEvent(&ev))
	{
          if (ev.type == SDL_QUIT || ev.type == SDL_KEYDOWN)
            if (ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
	      {
		_mutex.unlock();
		SDL_VideoQuit();
		return (stop = true, 0);
	      }
          if (ev.type == SDL_KEYDOWN || ev.type == SDL_MOUSEBUTTONDOWN ||
              ev.type == SDL_MOUSEBUTTONUP || ev.type == SDL_MOUSEMOTION ||
              ev.type == SDL_MOUSEWHEEL)
	    _win.checkEvent(ev);
        }

      dims = _win.getDimensions();
      _win.getRenderer().renderClear();
      _win.getRenderer().renderCopy(_win.getBackground(), dims, dims);
      /**/
      C.render(_win.getZBuffer(), _tmgr.getCmgr());
      /**/
      _win.createForeground();

      Renderer		&r = _win.getRenderer();
      _mutex.unlock();
      r.renderPresent();
      fpsMgr.show();
    }
  SDL_VideoQuit();
  return (stop = true, 0);
}

int			Displayer::execute(const std::string &arg)
{
  std::istringstream	st(arg);
  std::string		token;

  if (st >> token)
    if (_ptrMtd[token])
      {
	ScopedLock	lock(_mutex);
	return ((this->*_ptrMtd[token])(st));
      }
  return (-1);
}

int			Displayer::msz(std::istringstream &arg)
{
  int			x, y;
  std::string		err;

  if (!(arg >> x) || !(arg >> y) || (arg >> err))
    return (std::cerr << "Received bad command : msz" << std::endl, -1);
  if (x > 100 || y > 100 || x < 1 || y < 1)
    return (std::cerr << "msz : x and y must be <= 100 && >= 1" << std::endl, -1);
  _win.setMapWidth(x);
  _win.setMapHeight(y);
  _map.setWidth(x);
  _map.setHeight(y);
  _map.init();
  _win.create();
  return (0);
}

int			Displayer::bct(std::istringstream &arg)
{
  int			x, y;
  int			rocks[7];
  std::string		err;

  if (!(arg >> x) || !(arg >> y))
    return (std::cerr << "Received bad command : bct" << std::endl, -1);
  for (unsigned int i = 0; i < 7; i++)
    if (!(arg >> rocks[i]))
      return (std::cerr << "Received bad command : bct" << std::endl, -1);
  if ((arg >> err))
    return (std::cerr << "Received bad command : bct" << std::endl, -1);
  _map.setRocks(x, y, rocks);
  return (0);
}

int			Displayer::tna(std::istringstream &arg)
{
  std::string		tmp;

  _teams.clear();
  while (arg >> tmp)
    _teams.push_back(tmp);
  return (0);
}

int			Displayer::pnw(std::istringstream &arg)
{
  int			id, x, y, lvl;
  char			dir;
  std::string		team;
  std::string		err;

  if (!(arg >> id)  || !(arg >> x)   || !(arg >> y) ||
      !(arg >> dir) || !(arg >> lvl) || !(arg >> team) || (arg >> err))
    return (std::cerr << "Received bad command : pnw" << std::endl, -1);
  if (_players[id])
    return (std::cerr << "Player" << id << "already exists" << std::endl, -1);
  _players[id] = new Charset;
  _players[id]->setPosX(x);
  _players[id]->setPosY(y);
  _players[id]->setLvl(lvl);
  _players[id]->setTeam(team);
  _players[id]->setDirection(static_cast<Direction>(dir % 4));
  return (0);
}

int			Displayer::ppo(std::istringstream &arg)
{
  int			id, x, y;
  char			dir;
  std::string		err;

  if (!(arg >> id) || !(arg >> x) || !(arg >> y) || !(arg >> dir) || (arg >> err))
    return (std::cerr << "Received bad command : ppo" << std::endl, -1);
  if (!_players[id])
    return (std::cerr << "No Player" << id << std::endl, -1);
  _players[id]->setPosX(x);
  _players[id]->setPosY(y);
  _players[id]->setDirection(static_cast<Direction>(dir % 4));
  return (0);
}

int			Displayer::plv(std::istringstream &arg)
{
  int			id, lvl;
  std::string		err;

  if (!(arg >> id) || !(arg >> lvl) || (arg >> err))
    return (std::cerr << "Received bad command : pvl" << std::endl, -1);
  if (!_players[id])
    return (std::cerr << "No Player" << id << std::endl, -1);
  _players[id]->setLvl(lvl);
  return (0);
}

int			Displayer::pin(std::istringstream &arg)
{
  int			id, x, y;
  int			rocks[7];
  std::string		err;

  if (!(arg >> id) || !(arg >> x) || !(arg >> y))
    return (std::cerr << "Received bad command : pin" << std::endl, -1);
  for (unsigned int i = 0; i < 7; i++)
    if (!(arg >> rocks[i]))
      return (std::cerr << "Received bad command : pin" << std::endl, -1);
  if ((arg >> err))
    return (std::cerr << "Received bad command : pin" << std::endl, -1);
  if (!_players[id])
    return (std::cerr << "No Player" << id << std::endl, -1);
  _players[id]->setInv(rocks);
  return (0);
}

int			Displayer::pic(std::istringstream &arg)
{
  int			x, y, lvl;

  if (!(arg >> x) || !(arg >> y) || !(arg >> lvl))
    return (std::cerr << "Received bad command : pic" << std::endl, -1);
  _map.setUp(x, y, lvl, true, false);
  return (0);
}
int			Displayer::pie(std::istringstream &arg)
{
  int			x, y;
  bool			res;

  if (!(arg >> x) || !(arg >> y) || !(arg >> res))
    return (std::cerr << "Received bad command : pie" << std::endl, -1);
  _map.setUp(x, y, 0, false, res);
  return (0);
}

int			Displayer::pdr(std::istringstream &arg)
{
  int			id, i;
  std::string		err;

  if (!(arg >> id) || !(arg >> i) || (arg >> err))
    return (std::cerr << "Received bad command : pdr" << std::endl, -1);
  if (!_players[id])
    return (std::cerr << "No Player" << id << std::endl, -1);
  _map.addRock(_players[id]->getPosX(), _players[id]->getPosY(), i);
  return (0);
}

int			Displayer::pgt(std::istringstream &arg)
{
  int			id, i;
  std::string		err;

  if (!(arg >> id) || !(arg >> i) || (arg >> err))
    return (std::cerr << "Received bad command : pgt" << std::endl, -1);
  if (!_players[id])
    return (std::cerr << "No Player" << id << std::endl, -1);
  _map.removeRock(_players[id]->getPosX(), _players[id]->getPosY(), i);
  return (0);
}

int			Displayer::pdi(std::istringstream &arg)
{
  int			id;
  std::string		err;

  if (!(arg >> id) || (arg >> err))
    return (std::cerr << "Received bad command : pdi" << std::endl, -1);
  if (!_players[id])
    return (std::cerr << "No Player" << id << std::endl, -1);
  _players[id]->kill();
  return (0);
}

int			Displayer::enw(std::istringstream &arg)
{
  int			ide, idp, x, y;
  std::string		err;

  if (!(arg >> ide) || !(arg >> idp) || !(arg >> x) || !(arg >> y) || (arg >> err))
    return (std::cerr << "Received bad command : enw" << std::endl, -1);
  // if (!_eggs[ide])
  //   return (std::cerr << "Egg " << id << "Already exists" << std::endl, -1);
  if (!_players[idp])
    return (std::cerr << "No Player" << idp << std::endl, -1);
  // _eggs[ide] = new Egg(x, y, idp);
  return (0);
}

int			Displayer::eht(std::istringstream &arg)
{
  int			ide;
  std::string		err;

  if (!(arg >> ide) || (arg >> err))
    return (std::cerr << "Received bad command : eht" << std::endl, -1);
  // if (!_eggs[ide])
  //   return (std::cerr << "No Egg " << id << std::endl, -1);
  // _eggs[ide]->setOk();
  return (0);
}

int			Displayer::ebo(std::istringstream &arg)
{
  int			ide;
  std::string		err;

  if (!(arg >> ide) || (arg >> err))
    return (std::cerr << "Received bad command : ebo" << std::endl, -1);
  // if (!_eggs[ide])
  //   return (std::cerr << "No Egg " << id << std::endl, -1);
  // delete _eggs[ide];
  // _eggs[ide] = NULL;
  return (0);
}

int			Displayer::edi(std::istringstream &arg)
{
  int			ide;
  std::string		err;

  if (!(arg >> ide) || (arg >> err))
    return (std::cerr << "Received bad command : edi" << std::endl, -1);
  // if (!_eggs[ide])
  //   return (std::cerr << "No Egg " << id << std::endl, -1);
  // delete _eggs[ide];
  // _eggs[ide] = NULL;
  return (0);
}

int			Displayer::sgt(std::istringstream &arg)
{
  int			t;
  std::string		err;

  if (!(arg >> t) || (arg >> err))
    return (std::cerr << "Received bad command : sgt" << std::endl, -1);
  _time = t;
  return (0);
}

int			Displayer::seg(std::istringstream &arg)
{
  std::string		team;
  std::string		err;

  if (!(arg >> team) || (arg >> err))
    return (std::cerr << "Received bad command : seg" << std::endl, -1);
  auto it = find(_teams.begin(), _teams.end(), team);
  if (it == _teams.end())
    std::cerr << "No such team : " << team << std::endl;
  _teams.clear();
  _teams.push_back(team);
  _end = true;
  return (0);
}

int			Displayer::pex(std::istringstream &) {return (0);}
int			Displayer::pbc(std::istringstream &) {return (0);}
int			Displayer::pfk(std::istringstream &) {return (0);}
int			Displayer::smg(std::istringstream &) {return (0);}
int			Displayer::suc(std::istringstream &) {return (0);}
int			Displayer::sbp(std::istringstream &) {return (0);}
