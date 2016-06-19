//
// ScopedPtr.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Jun 10 13:35:59 2016 guillaume wilmot
// Last update Sun Jun 12 21:59:31 2016 guillaume wilmot
//

#ifndef SCOPEDPTR_HPP_
# define SCOPEDPTR_HPP_

# include <iostream>
# include <stddef.h>

template <class C>
class		ScopedPtr {
public:
  ScopedPtr<C>()				{_ptr = NULL;}
  ScopedPtr<C>(C *s)				{_ptr = s;}
  ScopedPtr(const ScopedPtr &s)			{_ptr = s.get();}
  ~ScopedPtr()					{if (_ptr) delete _ptr;}

  void		set(C *s)			{_ptr = s;}
  C		*get() const			{return (_ptr);}

  ScopedPtr	&operator>>(C *s)		{s = _ptr; return (*this);}
  ScopedPtr	&operator<<(C *s)		{_ptr = s; return (*this);}

private:
  ScopedPtr	&operator=(const ScopedPtr &)	{return (*this);}

  C		*_ptr;
};

#endif /* !SCOPEDPTR_HPP_ */
