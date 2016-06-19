//
// Sdl.hpp for sdl in /Users/noboud_n/Documents/Share/cpp_indie_studio/includes/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sat Jun  4 15:05:08 2016 Nyrandone Noboud-Inpeng
// Last update Sun Jun  5 22:43:43 2016 guillaume wilmot
//

#ifndef SDL_HPP_
# define SDL_HPP_

# include "SDL.h"
# include "SDL_mixer.h"
# include "Enum.hh"
# include "ProtectedVar.hpp"

# define LOAD_MENU_THEME	"./assets/sounds/MenuTheme.wav"
# define LOAD_GAME_MUSIC	"./assets/sounds/GameMusic.wav"
# define LOAD_CREDITS_MUSIC	"./assets/sounds/Credits.wav"
# define LOAD_HIGHSCORES_MUSIC	"./assets/sounds/HighScores.wav"
# define SOUND_PICKPOWERUP	"./assets/sounds/PickPowerUp.wav"
# define SOUND_EXPLODEBOMB	"./assets/sounds/ExplodeBomb.wav"
# define SOUND_PUTBOMB		"./assets/sounds/PutBomb.wav"
# define SOUND_DEATH		"./assets/sounds/Death.wav"
# define SOUND_FALLINGBLOCK	"./assets/sounds/FallingBlock.wav"
# define SOUND_SPLASH		"./ressources/videos/ScredSplashScreen_audio.wav"
# define SOUND_INTRO		"./ressources/videos/ScredIntro_audio.wav"

typedef struct		s_sounds
{
  Mix_Chunk		*pickPowerUp;
  Mix_Chunk		*explodeBomb;
  Mix_Chunk		*soundClick;
  Mix_Chunk		*putBomb;
}			t_sounds;

class			SDL
{
public:
  static SDL		&get() {static SDL _mgr; return (_mgr);}

  void			init();
  void			playSound(e_sound);
  void			playMusic(e_sound);
  void			actualizeVolume(e_sound) const;
  void			setVolume(float volume) { _volume = volume; }

private:

  SDL() {};
  SDL(const SDL &);

  void			operator=(const SDL &);

  float			_volume;
  std::map<e_sound, Mix_Chunk *>	_sounds;
  t_sounds		_chunks;
  Mix_Music		*_menuMusic;
  Mix_Music		*_gameMusic;
  Mix_Music		*_creditsMusic;
  Mix_Music		*_highscoresMusic;
};

#endif /* !SDL_HPP_ */
