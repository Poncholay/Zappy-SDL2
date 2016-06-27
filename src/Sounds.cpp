//
// Sdl.cpp for Sdl in /Users/noboud_n/Documents/Share/cpp_indie_studio/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sat Jun  4 16:06:16 2016 Nyrandone Noboud-Inpeng
// Last update Mon Jun 27 11:38:41 2016 guillaume wilmot
//

#include <unistd.h>
#include <iostream>
#include <random>
#include <exception>
#include "Sounds.hpp"

void			Sounds::init()
{
  Mix_Chunk	*tmp;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      std::cerr << Mix_GetError() << std::endl;
      return ;
    }
  for (unsigned int i = 0; i < 6; i++)
    {
      if (!(tmp = Mix_LoadWAV(std::string("./assets/sounds/death/" + std::to_string(i) + ".wav").c_str())))
	{
	  std::cerr << "Could not load " << std::string("./assets/sounds/death/" + std::to_string(i) + ".wav") << std::endl;
	  throw std::exception();
	}
      _sounds[DEATH].push_back(tmp);
    }
  for (unsigned int i = 0; i < 3; i++)
    {
      if (!(tmp = Mix_LoadWAV(std::string("./assets/sounds/grab/" + std::to_string(i) + ".wav").c_str())))
	{
	  std::cerr << "Could not load " << std::string("./assets/sounds/grab/" + std::to_string(i) + ".wav") << std::endl;
	  throw std::exception();
	}
      _sounds[PICK].push_back(tmp);
    }
  for (unsigned int i = 0; i < 1; i++)
    {
      if (!(tmp = Mix_LoadWAV(std::string("./assets/sounds/spawn/" + std::to_string(i) + ".wav").c_str())))
	{
	  std::cerr << "Could not load " << std::string("./assets/sounds/spawn/" + std::to_string(i) + ".wav") << std::endl;
	  throw std::exception();
	}
      Mix_VolumeChunk(tmp, 10);
      _sounds[SPAWN].push_back(tmp);
    }
  for (unsigned int i = 0; i < 1; i++)
    {
      if (!(tmp = Mix_LoadWAV(std::string("./assets/sounds/victory/" + std::to_string(i) + ".wav").c_str())))
	{
	  std::cerr << "Could not load " << std::string("./assets/sounds/victory/" + std::to_string(i) + ".wav") << std::endl;
	  throw std::exception();
	}
      _sounds[VICTORY].push_back(tmp);
    }
  for (unsigned int i = 0; i < 6; i++)
    {
      if (!(tmp = Mix_LoadWAV(std::string("./assets/sounds/voices/" + std::to_string(i) + ".wav").c_str())))
	{
	  std::cerr << "Could not load " << std::string("./assets/sounds/voices/" + std::to_string(i) + ".wav") << std::endl;
	  throw std::exception();
	}
      _sounds[VOICES].push_back(tmp);
    }
  if (!(_gameMusic = Mix_LoadMUS("./assets/sounds/music.wav")))
    {
      std::cerr << "Could not load " << std::string("./assets/sounds/music.wav") << std::endl;
      throw std::exception();
    }
  Mix_VolumeMusic(60);
  _loaded = true;
}

void			Sounds::playSound(e_sound sound)
{
  static std::default_random_engine	rander(time(NULL));

  if (!_loaded)
    return ;
  if (_sounds[sound].size() != 0 && sound != MUSIC)
    Mix_PlayChannel(-1, _sounds[sound][rander() % _sounds[sound].size()], 0);
}

void			Sounds::playMusic(e_sound music)
{
  if (!_loaded)
    return ;
  if (music == MUSIC)
    if (Mix_PlayMusic(_gameMusic, -1) == -1)
      return ;
}
