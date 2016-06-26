//
// Client.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/Zappy-SDL2
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Jun 26 15:09:30 2016 guillaume wilmot
// Last update Sun Jun 26 18:54:56 2016 guillaume wilmot
//

#include <iostream>
#include "Client.hpp"
#include "ZClient.hpp"
#include "Displayer.hpp"

void			Client::create(bool &stop, bool &start, const std::string &host, int port)
{
  std::string		tmp;
  fd_set		readf;
  fd_set		writef;
  struct timeval	tv;
  bool			begin = false;
  ZClient		&c = ZClient::get();

  c.setHost(host);
  c.setPort(port);
  c.init();
  while (!Displayer::get() || !start)
    {
      if (stop)
        return ;
      usleep(100000);
    }
  while (!stop)
    {
      tv.tv_sec = 0;
      tv.tv_usec = 1000000;
      FD_ZERO(&readf);
      FD_ZERO(&writef);
      FD_SET(0, &readf);
      FD_SET(c.getFd(), &readf);
      if (!begin)
        FD_SET(c.getFd(), &writef);
      if (select(c.getFd() + 1, &readf, &writef, NULL, &tv) == -1)
        return ;
      if (FD_ISSET(0, &readf))
	{
	  if (std::getline(std::cin, tmp))
	    {
	      if (Displayer::get())
		Displayer::get()->execute(tmp);
	    }
	  else if (std::cin.eof())
	    {
	      if (isatty(0))
		stop = true;
	      return ;
	    }
	}
      if (FD_ISSET(c.getFd(), &readf))
        {
          if (c.read() == -1)
            {
              stop = true;
              return ;
            }
          while ((c.getCmd(tmp)) != -1)
	    if (Displayer::get())
		Displayer::get()->execute(tmp);
        }
      if (!begin)
        if (FD_ISSET(c.getFd(), &writef))
          {
	    c.write(std::string("GRAPHIC\n"));
            begin = true;
          }
    }
}
