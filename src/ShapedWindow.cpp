//
// ShapedWindow.cpp for zappy in /home/wilmot_g/Gnome
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sat Jun 11 16:15:24 2016 guillaume wilmot
// Last update Mon Jun 20 12:11:34 2016 guillaume wilmot
//

#include <iostream>
#include "ShapedWindow.hpp"
#include "SDL2_rotozoom.h"

ShapedWindow::ShapedWindow(const std::string &name, int w, int h)
{
  _window = NULL;
  _screen = NULL;
  _tbg = NULL;
  _tmgr = NULL;
  _zbuff = NULL;
  _background = NULL;
  _name = name;
  _dragging = false;
  _smoother = 0;
  _supDims.w = TX;
  _supDims.h = TY;
  _windowPos.x = 150;
  _windowPos.y = 150;
  _mapWidth = w;
  _mapHeight = h;
  _update = false;
  srand(time(NULL));
  _seed = rand();
}

ShapedWindow::~ShapedWindow() {destroy();}

void			ShapedWindow::destroy()
{
  if (_tbg)
    SDL_DestroyTexture(_tbg);
  if (_window)
    SDL_DestroyWindow(_window);
}

int			ShapedWindow::create()
{
  int			p;

  if (!(p = (_mapWidth + _mapHeight - (_mapWidth + _mapHeight) % 2) / 2 + 1))
    p = 1;
  _scale = _supDims.w / p < _supDims.h / p * 2 ? _supDims.w / p : _supDims.h / p * 2;

  if (_tmgr->init(_scale) == -1)
    return (-1);
  if (!_window)
    {
      if (!(_window = SDL_CreateShapedWindow("Zappy", _windowPos.x, _windowPos.y, WINX, WINY, 0)))
	return (std::cerr << "Could not create window." << std::endl, -1);
      if (_renderer.init(_window) == -1)
	return (-1);
      _tmgr->setRenderer(&_renderer);
      _zbuff->setRenderer(&_renderer);
    }
  if (_tmgr->update() == -1)
    return (-1);

  SDL_SetWindowPosition(_window, _windowPos.x, _windowPos.y);
  if (!(createShape()))
    return (-1);
  if (SDL_ISPIXELFORMAT_ALPHA(_surface->format->format))
    {
      _mode.mode = ShapeModeBinarizeAlpha;
      _mode.parameters.binarizationCutoff = 255;
    }
  else
    {
      SDL_Color		black;
      memset(&black, 0, sizeof(SDL_Color));
      _mode.mode = ShapeModeColorKey;
      _mode.parameters.colorKey = black;
    }
  SDL_SetWindowSize(_window, _surface->w, _surface->h);
  SDL_SetWindowShape(_window, _surface, &_mode);
  if (!createBackground() || !createTexture())
    return (-1);
  return (0);
}

SDL_Texture		*ShapedWindow::createTexture()
{
  if (_tbg)
    SDL_DestroyTexture(_tbg);
  if (!(_tbg = SDL_CreateTextureFromSurface(_renderer.get(), _background)))
    {
      std::cerr << "Could not create texture." << std::endl;
      return (NULL);
    }

  Uint32		pixelFormat = 0;

  memset(&_dims, 0, sizeof(SDL_Rect));
  SDL_QueryTexture(_tbg, &pixelFormat, NULL, &_dims.w, &_dims.h);
  return (_tbg);
}

SDL_Surface		*ShapedWindow::createShape()
{
  std::vector<TextureManager::surface>	&cube = _tmgr->getV("cube");
  std::vector<TextureManager::surface>	&vine = _tmgr->getV("vine");
  std::vector<TextureManager::surface>	&tree = _tmgr->getV("tree");
  std::vector<TextureManager::surface>	&bush = _tmgr->getV("bush");
  TextureManager::surface		tmp;
  SDL_Rect				pos;

  srand(_seed);
  tmp = cube[rand() % cube.size()];
  for (int i = 0; i < _mapHeight; i++)
    for (int j = 0; j < _mapWidth; j++)
      {
	pos.w = tmp.surface->w;
	pos.h = tmp.surface->h;
	pos.x = (i + j) * 1.0 * pos.w / 2;
	pos.y = (_mapWidth - (j + 1) + i) * 1.0 * pos.h / 4;
	_zbuff->add(tmp, NULL, &pos, 2);
	if (i == _mapHeight - 1 || j == 0 ? 1 : 0)
	  {
	    if (rand() % 5 == 0)
	      {
		pos.y += j == 0 ? 1.0 * pos.h / 4 : 1.0 * pos.h / 1.5;
		_zbuff->add(vine[rand() % vine.size()], NULL, &pos, 2);
	      }
	  }
	else if (rand() % 15 == 0)
	  {
	    pos.y -= 1.0 * pos.h / 2;
	    _zbuff->add(tree[rand() % tree.size()], NULL, &pos, 2);
	  }
	else if (rand() % 8 == 0)
	  {
	    pos.y -= 1.0 * pos.h / 2;
	    _zbuff->add(bush[rand() % bush.size()], NULL, &pos, 2);
	  }
      }
  return (_surface = _zbuff->renderToSurface());
}

SDL_Surface		*ShapedWindow::createBackground()
{
  const std::vector<TextureManager::surface>	&cube = _tmgr->getV("cube");
  TextureManager::surface		tmp;
  SDL_Rect				pos;

  srand(_seed);
  tmp = cube[rand() % cube.size()];
  for (int i = 0; i < _mapHeight; i++)
    for (int j = 0; j < _mapWidth; j++)
      {
	if (!tmp.surface)
	  continue;
	pos.w = tmp.surface->w;
	pos.h = tmp.surface->h;
	pos.x = (i + j) * 1.0 * pos.w / 2;
	pos.y = (_mapWidth - (j + 1) + i) * 1.0 * pos.h / 4;
	_zbuff->add(tmp, NULL, &pos);
      }
  return (_background = _zbuff->renderToSurface());
}

void			ShapedWindow::createForeground()
{
  const std::vector<TextureManager::surface>	&cube = _tmgr->getV("cube");
  const std::vector<TextureManager::surface>	&vine = _tmgr->getV("vine");
  const std::vector<TextureManager::surface>	&tree = _tmgr->getV("tree");
  const std::vector<TextureManager::surface>	&bush = _tmgr->getV("bush");
  TextureManager::surface		tmp;
  TextureManager::surface		tmp2;
  SDL_Rect				pos;

  srand(_seed);
  tmp = cube[rand() % cube.size()];
  for (int i = 0; i < _mapHeight; i++)
    for (int j = 0; j < _mapWidth; j++)
      if (i == _mapHeight - 1 || j == 0 ? 1 : 0)
	{
	  if (rand() % 5 == 0)
	    {
	      tmp2 = vine[rand() % vine.size()];
	      pos.w = tmp2.surface->w;
	      pos.h = tmp2.surface->h;
	      pos.x = (i + j) * 1.0 * tmp.surface->w / 2;
	      pos.y = (_mapWidth - (j + 1) + i) * 1.0 * tmp.surface->h / 4;
	      pos.y += j == 0 ? 1.0 * tmp.surface->h / 4 : 1.0 * tmp.surface->h / 1.5;
	      _zbuff->add(tmp2, NULL, &pos, 2);
	    }
	}
      else if (rand() % 15 == 0)
	{
	  tmp2 = tree[rand() % tree.size()];
	  pos.x = (i + j) * 1.0 * tmp.surface->w / 2;
	  pos.y = (_mapWidth - (j + 1) + i) * 1.0 * tmp.surface->h / 4;
	  pos.y -= 1.0 * tmp.surface->h / 2;
	  pos.w = tmp2.surface->w;
	  pos.h = tmp2.surface->h;
	  _zbuff->add(tmp2, NULL, &pos, 2);
	}
      else if (rand() % 8 == 0)
	{
	  tmp2 = bush[rand() % bush.size()];
	  pos.x = (i + j) * 1.0 * tmp.surface->w / 2;
	  pos.y = (_mapWidth - (j + 1) + i) * 1.0 * tmp.surface->h / 4;
	  pos.y -= 1.0 * tmp.surface->h / 2;
	  pos.w = tmp2.surface->w;
	  pos.h = tmp2.surface->h;
	  _zbuff->add(tmp2, NULL, &pos, 2);
	}
  _zbuff->render();
}

void			ShapedWindow::checkEvent(const SDL_Event &ev)
{
  moveCamera(ev);
  moveWindow(ev);
  resize(ev);
}

void			ShapedWindow::moveCamera(const SDL_Event &ev)
{
  if (ev.type == SDL_KEYDOWN)
    {
      if (ev.key.keysym.sym == SDLK_UP)
	_zbuff->incY(100);
      else if (ev.key.keysym.sym == SDLK_RIGHT)
	_zbuff->incX(-50);
      else if (ev.key.keysym.sym == SDLK_DOWN)
	_zbuff->incY(-100);
      else if (ev.key.keysym.sym == SDLK_LEFT)
	_zbuff->incX(50);
      if (ev.key.keysym.mod & KMOD_SHIFT)
	{
	  if (ev.key.keysym.sym == SDLK_c)
	    _zbuff->center();
	}
      else if (ev.key.keysym.sym == SDLK_c)
	SDL_SetWindowPosition(_window, 0, 0);
    }
}

void			ShapedWindow::moveWindow(const SDL_Event &ev)
{
  if (ev.type == SDL_MOUSEBUTTONDOWN)
    {
      SDL_GetMouseState(&_mWindowResizeOffset.x, &_mWindowResizeOffset.y);
      SDL_GetWindowPosition(_window, &_windowPos.x, &_windowPos.y);
      _dragging = true;
    }
  else if (ev.type == SDL_MOUSEBUTTONUP)
    _dragging = false;
  else if (ev.type == SDL_MOUSEMOTION && _dragging)
    {
      SDL_GetMouseState(&_mousePos.x, &_mousePos.y);
      SDL_GetWindowPosition(_window, &_newWindowPos.x, &_newWindowPos.y);
      _newWindowPos.x = _newWindowPos.x + _mousePos.x - _mWindowResizeOffset.x;
      _newWindowPos.y = _newWindowPos.y + _mousePos.y - _mWindowResizeOffset.y;
      _newWindowPos.x = _newWindowPos.x > 1920 - 50 ? 1920 - 50 : _newWindowPos.x;
      _newWindowPos.x = _newWindowPos.x < 50 - _dims.w ? 50 - _dims.w : _newWindowPos.x;
      _newWindowPos.y = _newWindowPos.y > 950 ? 950 : _newWindowPos.y;
      _newWindowPos.y = _newWindowPos.y < 50 - _dims.h ? 50 - _dims.h : _newWindowPos.y;

      SDL_SetWindowPosition(_window, _newWindowPos.x, _newWindowPos.y);
      _windowPos = _newWindowPos;
    }
}

void			ShapedWindow::resize(const SDL_Event &ev)
{
  if (ev.type == SDL_MOUSEWHEEL)
    {
      _smoother += ev.wheel.y;
      if (_smoother == 5 && _supDims.h < 1500)
	{
	  _supDims.h += 100;
	  _supDims.w += 200;
	  _update = true;
	}
      if (_smoother == -5 && _supDims.h > 200)
	{
	  _supDims.h -= 100;
	  _supDims.w -= 200;
	  _update = true;
	}
      _smoother = _smoother == 5 || _smoother == -5 ? 0 : _smoother;
      if (_update)
	{
	  _update = false;
	  _zbuff->center();
	  // destroy();
	  create();
	}
    }
}

void			ShapedWindow::biggest()
{
  _mapBiggest = _mapHeight > _mapWidth ? _mapHeight : _mapWidth;
}
