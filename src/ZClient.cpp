//
// ZClient.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/client
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 15:44:09 2016 guillaume wilmot
// Last update Sun Jun 26 18:55:26 2016 guillaume wilmot
//

#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "ZClient.hpp"
#include "ScopedLock.hpp"

ZClient::ZClient() {}
ZClient::~ZClient() {}

int		ZClient::write(const std::string &buff)
{
  ScopedLock	lock(_mutex);

  if (::write(_sock, buff.c_str(), buff.length()) == -1)
    return (-1);
  return (0);
}

int		ZClient::read()
{
  ScopedLock	lock(_mutex);
  int		n = 0;
  unsigned int	sinsize = sizeof _sin;

  if ((n = recvfrom(_sock, _buffer, 4096 - 1, 0, (sockaddr *)&_sin, &sinsize)) <= 0)
    return (-1);
  _buffer[n] = 0;
  _rest += _buffer;
  return (n);
}

int		ZClient::getCmd(std::string &cmd)
{
  ScopedLock	lock(_mutex);

  if (_rest.find("\n") == std::string::npos)
    return (-1);
  cmd = _rest.substr(0, _rest.find("\n"));
  _rest = _rest.substr(_rest.find("\n") + 1);
  cmd.erase(std::remove(cmd.begin(), cmd.end(), '\r'), cmd.end());
  return (0);
}

int		ZClient::init()
{
  ScopedLock	lock(_mutex);

  _sock = socket(AF_INET, SOCK_STREAM, 0);
  if (_sock == -1 || (_hostinfo = gethostbyname(_host.c_str())) == NULL)
    return (std::cerr << "Could not init socket" << std::endl, -1);
  _sin.sin_addr = *(in_addr *) _hostinfo->h_addr;
  _sin.sin_port = htons(_port);
  _sin.sin_family = AF_INET;
  if ((connect(_sock, (struct sockaddr *) &_sin, sizeof(struct sockaddr))) == -1)
    return (std::cerr << "Could not connect" << std::endl, -1);
  return (0);
}

std::string	ZClient::getIp()	{ScopedLock	lock(_mutex); return (std::string(_host));}
int		ZClient::getPort()	{ScopedLock	lock(_mutex); return (_port);}
int		ZClient::getFd()	{ScopedLock	lock(_mutex); return (_sock);}
