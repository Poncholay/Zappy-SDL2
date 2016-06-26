//
// Server.hh for  in /home/empoci_k/rendu_tek2/cpp_indie_studio/nekfeu/server
//
// Made by Kévin Empociello
// Login   <empoci_k@epitech.net>
//
// Started on  Wed Apr 27 15:21:29 2016 Kévin Empociello
// Last update Sun Jun 26 16:22:53 2016 guillaume wilmot
//

#ifndef ZCLIENT_H
# define ZCLIENT_H

# include <unistd.h>
# include <netdb.h>
# include <string.h>
# include "Mutex.hpp"

class ZClient {
public:
  ZClient();
  ~ZClient();

  static ZClient	&get() {static ZClient c; return (c);}

  int			write(const std::string &);
  int			init();
  int			read();
  int			getCmd(std::string &);
  std::string		getIp();
  int			getPort();
  int			getFd();

  void			setHost(const std::string &h) {_host = h;}
  void			setPort(int p) {_port = p;}

private:
  struct hostent	*_hostinfo;
  std::string		_username;
  sockaddr_in		_sin;
  fd_set		_rdfs;
  char			_buffer[4096];
  std::string		_rest;
  int			_sock;
  int			_port;
  std::string		_host;
  Mutex			_mutex;
};

#endif //ZCLIENT_H
