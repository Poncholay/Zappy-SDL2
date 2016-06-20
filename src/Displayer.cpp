//
// Displayer.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:30:55 2016 guillaume wilmot
// Last update Mon Jun 20 16:22:44 2016 guillaume wilmot
//

#include "FpsManager.hpp"
#include "Displayer.hpp"
#include "Charset.hh"

Displayer::Displayer() : _win("Zappy", 15, 15), _zbuff(WINX, WINY) {}

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

  Charset            C("assets/textures/charsets/lvl1/moving/image.png");
  if (C.load(15, 4, _win.getRenderer()) == -1)
    return (-1);
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
      C.render(_win.getZBuffer());
      _win.createForeground();
      _win.getRenderer().renderPresent();
      fpsMgr.show();
    }
  SDL_VideoQuit();
  return (0);
}
