//
// Client.hpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 26 15:12:19 2016 guillaume wilmot
// Last update Sun Jun 26 15:16:41 2016 guillaume wilmot
//

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

class		Client {
public:
  Client() {}
  ~Client() {}

  static void	create(bool &, bool &, const std::string &, int);

private:
  Client(const Client &) {}
  Client	&operator=(const Client &) {return (*this);}
};

#endif /* !CLIENT_HPP_ */
