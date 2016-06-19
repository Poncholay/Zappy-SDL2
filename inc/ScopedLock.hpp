//
// ScopedLock.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:11 2016 guillaume wilmot
// Last update Fri May 27 02:08:00 2016 guillaume wilmot
//

#ifndef SCOPEDLOCK_HPP_
# define SCOPEDLOCK_HPP_

# include "Mutex.hpp"

class ScopedLock
{
public:
  ScopedLock(Mutex &mutex) {_lock = &mutex; _lock->lock();}
  ~ScopedLock() {_lock->unlock();}
private:
  Mutex		*_lock;
};

#endif /* !SCOPEDLOCK_HPP_ */
