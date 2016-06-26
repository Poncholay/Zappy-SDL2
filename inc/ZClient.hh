//
// Server.hh for  in /home/empoci_k/rendu_tek2/cpp_indie_studio/nekfeu/server
//
// Made by Kévin Empociello
// Login   <empoci_k@epitech.net>
//
// Started on  Wed Apr 27 15:21:29 2016 Kévin Empociello
// Last update Sun Jun 26 04:22:03 2016 guillaume wilmot
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
  std::string		_username;
  sockaddr_in		_sin;
  fd_set		_rdfs;
  char			_buffer[4096];
  std::string		_rest;
  int			_sock;
  int			_port;
  const char	       	*_host;

public:
  int			write(const std::string &);
  int			init();
  int			read();
  int			getCmd(std::string &);
  std::string		getIp() const;
  int			getPort() const;
  int			getFd() const;

  ZClient(const char *, int);
  ~ZClient();
};

#endif //ZCLIENT_H
