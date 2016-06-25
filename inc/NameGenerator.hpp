//
// NameGenerator.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sat Jun 25 23:49:46 2016 guillaume wilmot
// Last update Sat Jun 25 23:55:23 2016 guillaume wilmot
//

#ifndef NAMEGENERATOR_HPP_
# define NAMEGENERATOR_HPP_

class		NameGenerator {
public:
  NameGenerator();

  static std::string	generate();

private:
  NameGenerator(const NameGenerator &) {}
  NameGenerator		&operator=(NameGenerator &) {return (*this);}
};

#endif /* !NAMEGANERATOR_HPP_ */
