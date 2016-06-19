/*
** main.c for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Tue Jun  7 16:01:13 2016 guillaume wilmot
// Last update Sun Jun 19 16:26:35 2016 guillaume wilmot
*/

#include <iostream>
#include "SDL.h"
#include "ShapedWindow.hpp"
#include "Charset.hh"
#include "Map.hpp"
#include "ZClient.hh"

int		check(int argc, char **argv)
{
  if (argc < 3)
    return (std::cerr << "./zappy_gdx width height" << std::endl, -1);
  if (SDL_VideoInit(NULL) == -1)
    return (std::cerr << "Could not initialize SDL video." << std::endl, -1);
  if (std::atoi(argv[1]) > 100 || std::atoi(argv[2]) > 100)
    return (std::cerr << "Map is too big." << std::endl, -1);
  return (0);
}

int		main(int argc, char **argv)
{
  if (check(argc, argv) == -1)
    return (-1);

  // Map		map;
  ShapedWindow          w("Zappy", std::atoi(argv[1]), std::atoi(argv[2]));
  clock_t		deltaTime = 0;
  unsigned int		frames = 0;
  double		frameRate = 30;
  double		averageFrameTimeMilliseconds = 33.333;
  TextureManager	tmgr;
  ZBuffer		zbuff(WINX, WINY);


  w.setTmgr(&tmgr);
  w.setZbuff(&zbuff);
  if (w.create() == -1)
    return (-1);
  w.getRenderer().setRenderDrawColor(0, 0, 0xFF, 0xFF);

  // Charset		C("assets/textures/charsets/test.bmp");
  // C.setRenderer(w.getRenderer());
  // if (C.load(3, 4, 32, 156, 0) == -1)
  //   return (-1);
  // C.setPosY(100);
  // C.setPosX(100);

  while (1)
    {
      SDL_Event		ev;
      clock_t		beginFrame = clock();

      while (SDL_PollEvent(&ev))
        {
          if (ev.type == SDL_QUIT || ev.type == SDL_KEYDOWN)
            if (ev.type == SDL_QUIT || ev.key.keysym.sym == SDLK_ESCAPE)
              return (0);
  	  if (ev.type == SDL_KEYDOWN || ev.type == SDL_MOUSEBUTTONDOWN ||
  	      ev.type == SDL_MOUSEBUTTONUP || ev.type == SDL_MOUSEMOTION ||
  	      ev.type == SDL_MOUSEWHEEL)
          w.checkEvent(ev);
        }

      SDL_Rect          dims = w.getDimensions();
      w.getRenderer().renderClear();
      w.getRenderer().renderCopy(w.getBackground(), dims, dims);
      w.createForeground();
      // C.render(screen);
      w.getRenderer().renderPresent();

      clock_t		endFrame = clock();
      deltaTime += endFrame - beginFrame;
      frames++;
      if (deltaTime / (1.0 * CLOCKS_PER_SEC / 1000.0) > 1000.0)
  	{
  	  frameRate = 1.0 * frames * 0.5 + frameRate * 0.5;
  	  frames = 0;
  	  deltaTime -= CLOCKS_PER_SEC;
  	  averageFrameTimeMilliseconds = 1000.0 / (frameRate == 0 ? 0.001 : frameRate);

  	  std::cout << "FPS : " << 1000.0 / averageFrameTimeMilliseconds << std::endl;
  	}
    }
  SDL_VideoQuit();
  return (0);
}
