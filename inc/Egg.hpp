//
// Egg.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sat Jun 25 21:17:36 2016 guillaume wilmot
// Last update Sun Jun 26 01:47:14 2016 guillaume wilmot
//

#ifndef EGG_HPP_
# define EGG_HPP_

class		Egg {
public:
  Egg(int x, int y, int id, int w) {_x = x; _y = y; _id= id; _w = w; _timer = 0; _frame = 0;}

  int		render(TextureManager::surface &s, ZBuffer &b)
  {
    SDL_Rect	src;
    SDL_Rect	dest;

    if (!s.surface || !s.texture)
      return (-1);
    src.w = s.surface->w / 10;
    src.h = s.surface->h;
    src.x = (_frame % 10) * src.w;
    src.y = 0;
    dest.w = (s.surface->w / 10) * Scale::get()._x;
    dest.h = s.surface->h * 1.2 * Scale::get()._y;
    dest.x = (_x + _y) * 1.0 * Scale::get()._w / 2 + Scale::get()._w / 1.7;
    dest.y = (_w - (_y + 1) + _x) * 1.0 * Scale::get()._h / 4 - ((1.0 * dest.h) / 2.5);
    b.add(s, &src, &dest);
    if (_timer++ == 5)
      {
	_frame++;
	_timer = 0;
      }
    return (0);
  }

private:

  Egg(const Egg &) {}
  Egg		&operator=(const Egg &) {return (*this);}

  int		_x;
  int		_y;
  int		_w;
  int		_id;
  int		_frame;
  int		_timer;
};

#endif /* !EGG_HPP_ */
