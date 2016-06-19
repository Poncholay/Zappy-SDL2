//
// FpsManager.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:51:51 2016 guillaume wilmot
// Last update Sun Jun 19 19:16:26 2016 guillaume wilmot
//

#include <iostream>
#include "FpsManager.hpp"

void		FpsManager::apply() {_beginFrame = clock();}

void		FpsManager::show()
{
  _deltaTime += clock() - _beginFrame;
  _frames++;
  if (_deltaTime / (1.0 * CLOCKS_PER_SEC / 1000.0) > 1000.0)
    {
      _frameRate = 1.0 * _frames * 0.5 + _frameRate * 0.5;
      _frames = 0;
      _deltaTime -= CLOCKS_PER_SEC;
      _average = 1000.0 / (_frameRate == 0 ? 0.001 : _frameRate);

      std::cout << "FPS : " << 1000.0 / _average << std::endl;
    }
}
