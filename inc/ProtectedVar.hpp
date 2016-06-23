//
// ProtectedVar.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr  8 17:56:22 2016 guillaume wilmot
// Last update Fri May 27 02:18:27 2016 guillaume wilmot
//

#ifndef PROTECTEVAR_HPP_
# define PROTECTEVAR_HPP_

# include "Mutex.hpp"
# include "ScopedLock.hpp"

template <class C>
class			ProtectedVar {
public:
  ProtectedVar<C>() {}
  ~ProtectedVar() {}

  void			set(const C &var) {ScopedLock lock(_mutex); _var = var;}
  C			&get() {ScopedLock lock(_mutex); return (_var);}

  C			_var;
  Mutex			_mutex;
};

#endif /* !PROTECTEDVAR_HPP_ */
