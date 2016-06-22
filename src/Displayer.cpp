//
// Displayer.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:30:55 2016 guillaume wilmot
// Last update Wed Jun 22 14:41:38 2016 guillaume wilmot
//

#include <sstream>
#include <string>
#include "FpsManager.hpp"
#include "Displayer.hpp"
#include "Charset.hh"

Displayer::Displayer() : _win("Zappy", 15, 15), _zbuff(WINX, WINY)
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
}

void			Displayer::create()
{
  Displayer		d;

  if (SDL_VideoInit(NULL) == -1)
    {
      std::cerr << "Could not initialize SDL video." << std::endl;
      return ;
    }
  d.start();
  SDL_VideoQuit();
}

int			Displayer::start()
{
  FpsManager		fpsMgr;
  SDL_Event		ev;
  SDL_Rect		dims;

  _win.setTmgr(&_tmgr);
  _win.setZbuff(&_zbuff);
  if (_win.create() == -1)
    return (-1);
  _win.getRenderer().setRenderDrawColor(0, 0, 0, 0);

  Charset            C;
  C.setPosY(300);
  C.setPosX(300);

  while (1)
    {
      fpsMgr.apply();

      while (SDL_PollEvent(&ev))
	{
          if (ev.type == SDL_QUIT || ev.type == SDL_KEYDOWN)
            if (ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
              return (0);
          if (ev.type == SDL_KEYDOWN || ev.type == SDL_MOUSEBUTTONDOWN ||
              ev.type == SDL_MOUSEBUTTONUP || ev.type == SDL_MOUSEMOTION ||
              ev.type == SDL_MOUSEWHEEL)
	    _win.checkEvent(ev);
        }

      dims = _win.getDimensions();
      _win.getRenderer().renderClear();
      _win.getRenderer().renderCopy(_win.getBackground(), dims, dims);
      C.render(_win.getZBuffer(), _tmgr.getCmgr());
      _win.createForeground();
      _win.getRenderer().renderPresent();
      fpsMgr.show();
    }
  SDL_VideoQuit();
  return (0);
}

int			Displayer::execute(const std::string &arg)
{
  std::istringstream	st(arg);
  std::string		token;

  if (st >> token)
    if (_ptrMtd[token])
      {
	return ((this->*_ptrMtd[token])(st));
      }
  return (-1);
}

int			Displayer::msz(std::istringstream &arg)
{
  std::string		token;

  while (arg >> token)
    std::cout << token << std::endl;
  return (0);
}
int			Displayer::bct(std::istringstream &) {return (0);}
int			Displayer::tna(std::istringstream &) {return (0);}
int			Displayer::pnw(std::istringstream &) {return (0);}
int			Displayer::ppo(std::istringstream &) {return (0);}
int			Displayer::plv(std::istringstream &) {return (0);}
int			Displayer::pin(std::istringstream &) {return (0);}
int			Displayer::pex(std::istringstream &) {return (0);}
int			Displayer::pbc(std::istringstream &) {return (0);}
int			Displayer::pic(std::istringstream &) {return (0);}
int			Displayer::pie(std::istringstream &) {return (0);}
int			Displayer::pfk(std::istringstream &) {return (0);}
int			Displayer::pdr(std::istringstream &) {return (0);}
int			Displayer::pgt(std::istringstream &) {return (0);}
int			Displayer::pdi(std::istringstream &) {return (0);}
int			Displayer::enw(std::istringstream &) {return (0);}
int			Displayer::eht(std::istringstream &) {return (0);}
int			Displayer::ebo(std::istringstream &) {return (0);}
int			Displayer::edi(std::istringstream &) {return (0);}
int			Displayer::sgt(std::istringstream &) {return (0);}
int			Displayer::seg(std::istringstream &) {return (0);}
int			Displayer::smg(std::istringstream &) {return (0);}
int			Displayer::suc(std::istringstream &) {return (0);}
int			Displayer::sbp(std::istringstream &) {return (0);}
