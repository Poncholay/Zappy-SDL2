//
// Time.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun 21 11:45:26 2016 guillaume wilmot
// Last update Sat Jun 25 18:44:42 2016 guillaume wilmot
//

#ifndef TIME_HPP_
# define TIME_HPP_

# include <utility>

class		Time {
public:
  static Time		&get()				{static Time _s; return (_s);}

  Time			&operator>>(double &s)		{s = _time; return (*this);}
  Time			&operator<<(const int &s)	{_time = 1.0 / s; return (*this);}

private:

  Time()						{_time = 1.0 / 5;}
  Time(const Time &)					{}
  Time			&operator=(const Time &)	{return (*this);}

  double		_time;
};

#endif /* TIME_HPP_ */
