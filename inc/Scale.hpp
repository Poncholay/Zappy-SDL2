//
// Scale.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun 21 11:45:26 2016 guillaume wilmot
// Last update Tue Jun 21 23:22:34 2016 guillaume wilmot
//

#ifndef SCALE_HPP_
# define SCALE_HPP_

# include <utility>

class           Scale {
public:
  static Scale		&get()			{static Scale _s; return (_s);}

  void			set(float x, float y)	{_x = x; _y = y;}
  float			_x;
  float			_y;

private:

  Scale()						{}
  Scale(const Scale &)					{}
  Scale			&operator=(const Scale &)	{return (*this);}
};

#endif /* SCALE_HPP_ */
