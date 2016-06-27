//
// Sounds.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 26 22:16:31 2016 guillaume wilmot
// Last update Sun Jun 26 23:15:39 2016 guillaume wilmot
//

#ifndef Sounds_HPP_
# define Sounds_HPP_

# include <map>
# include "SDL.h"
# include "SDL_mixer.h"

enum    e_sound
  {
    MUSIC = 0,
    DEATH,
    PICK,
    SPAWN,
    VICTORY,
    DEFEAT,
    VOICES,
  };

class			Sounds
{
public:
  static Sounds		&get() {static Sounds _mgr; return (_mgr);}

  void			init();
  void			playSound(e_sound);
  void			playMusic(e_sound);

private:

  Sounds() {_loaded = false;};
  Sounds(const Sounds &);

  void			operator=(const Sounds &);

  std::map<e_sound, std::vector<Mix_Chunk *> >	_sounds;

  bool			_loaded;
  float			_volume;
  Mix_Music		*_gameMusic;
};

#endif /* !Sounds_HPP_ */
