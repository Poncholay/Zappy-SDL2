//
// Server.hh for  in /home/empoci_k/rendu_tek2/cpp_indie_studio/nekfeu/server
//
// Made by Kévin Empociello
// Login   <empoci_k@epitech.net>
//
// Started on  Wed Apr 27 15:21:29 2016 Kévin Empociello
// Last update Sun Jun 19 15:10:17 2016 guillaume wilmot
//

#ifndef ZCLIENT_H
# define ZCLIENT_H

# include <iostream>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <netdb.h>
# include <string.h>
# include <errno.h>

class ZClient {
private:
  struct hostent	*_hostinfo;
  struct timeval	_timeout;
  std::string		_username;
  sockaddr_in		_sin;
  fd_set		_rdfs;
  char			_buffer[4096];
  int			_sock;
  int			_x;
  int			_y;
  int			_port;
  const char	       	*_host;

public:
  void			writeServer(const char *);
  void			launch();
  void			init();
  int			readServer();
  std::string		getIp() const;
  int			getPort() const;

  ZClient(const char *, int);
  ~ZClient();
};

#endif //ZCLIENT_H
