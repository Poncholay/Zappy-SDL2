//
// Scale.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun 21 11:45:26 2016 guillaume wilmot
// Last update Tue Jun 21 12:16:26 2016 guillaume wilmot
//

#ifndef SCALE_HPP_
# define SCALE_HPP_

# include <utility>

class           Scale {
public:
  static Scale		&get()			{static Scale _s; return (_s);}

  void			set(int x, int y)	{_x = x; _y = y;}
  int			_x;
  int			_y;

private:

  Scale()						{}
  Scale(const Scale &)					{}
  Scale			&operator=(const Scale &)	{return (*this);}
};

#endif /* SCALE_HPP_ */
