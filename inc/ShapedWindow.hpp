//
// ShapedWindow.hpp for zappy in /home/wilmot_g/Gnome
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sat Jun 11 16:06:21 2016 guillaume wilmot
// Last update Mon Jun 20 22:37:57 2016 guillaume wilmot
//

#ifndef SHAPEDWINDOW_HPP_
# define SHAPEDWINDOW_HPP_

# include "SDL.h"
# include "SDL_shape.h"
# include "Renderer.hpp"
# include "TextureManager.hpp"
# include "ZBuffer.hpp"

# define WINX 1920
# define WINY 1080
# define TX 1200
# define TY 600

struct	Point {
  int	x;
  int	y;
};

class		ShapedWindow {
public:
  ShapedWindow(const std::string & = "", int = 10, int = 10);
  ~ShapedWindow();

  int			create();
  void			putThing(TextureManager::surface &, SDL_Rect &, int, int);
  void			checkEvent(const SDL_Event &ev);
  void			moveWindow(const SDL_Event &ev);
  void			moveCamera(const SDL_Event &ev);
  void			resize(const SDL_Event &ev);

  SDL_Texture		*createTexture();
  SDL_Surface		*createBackground();
  void			createForeground();
  SDL_Surface		*createShape();

  int			getHeight()		const		{return (_dims.h);}
  int			getWidth()		const		{return (_dims.w);}
  SDL_Surface		*getScreen()		const		{return (_screen);}
  SDL_Texture		*getBackground()	const		{return (_tbg);}
  SDL_Rect		getDimensions()		const		{return (_dims);}
  Renderer		&getRenderer()				{return (_renderer);}
  ZBuffer		&getZBuffer()				{return (*_zbuff);}
  TextureManager	&getTmgr()				{return (*_tmgr);}

  void			setName(const std::string &s)		{_name = s;}
  void			setMapHeight(int s)			{_mapHeight = s; biggest();}
  void			setMapWidth(int s)			{_mapWidth = s; biggest();}
  void			setTmgr(TextureManager *s)		{_tmgr = s;}
  void			setZbuff(ZBuffer *s)			{_zbuff = s;}

private:
  ShapedWindow(const ShapedWindow &)				{}
  ShapedWindow		&operator=(const ShapedWindow &)	{return (*this);}

  int			initTextureManager(int);
  void			biggest();
  void			destroy();

  SDL_Window		*_window;
  Renderer		_renderer;
  SDL_Surface		*_background;
  SDL_Texture		*_tbg;
  SDL_Surface		*_surface;
  SDL_Surface		*_screen;
  SDL_WindowShapeMode	_mode;
  SDL_Rect		_dims;
  SDL_Rect		_supDims;
  std::string		_name;

  int			_smoother;
  int			_update;

  float			_scale;
  int			_mapWidth;
  int			_mapHeight;
  int			_mapBiggest;
  unsigned int		_seed;

  bool			_dragging;
  Point			_mousePos;
  Point			_windowPos;
  Point			_newWindowPos;
  Point			_mWindowResizeOffset;

  TextureManager	*_tmgr;
  ZBuffer		*_zbuff;
};

#endif /* !SHAPEDWINDOW_HPP_ */
