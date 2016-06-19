//
// FpsManager.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 19 18:51:49 2016 guillaume wilmot
// Last update Sun Jun 19 19:14:36 2016 guillaume wilmot
//

#ifndef FPSMANAGER_HPP_
# define FPSMANAGER_HPP_

# include <time.h>

class		FpsManager {
public:
  FpsManager() {_deltaTime = 0; _frames = 0; _frameRate = 30; _average = 33.333;}
  ~FpsManager() {}

  void			apply();
  void			show();

private:

  clock_t		_beginFrame;
  clock_t		_deltaTime;
  unsigned int		_frames;
  double		_frameRate;
  double		_average;
};

#endif /* !FPSMANAGER_HPP_ */
