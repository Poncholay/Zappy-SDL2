//
// ZClient.cpp for zappy in /home/wilmot_g/Rendu/PSU_2015_zappy/LeHaineux/client
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Jun  7 15:44:09 2016 guillaume wilmot
// Last update Tue Jun  7 15:44:11 2016 guillaume wilmot
//

#include "ZClient.hh"

std::string ZClient::getIp() const {
  return std::string(_host);
}

int	ZClient::getPort() const {
  return _port;
}

void ZClient::writeServer(const char *buffer) {
  printf("## [%s] sent ##\n", buffer);
  if (sendto(_sock, buffer, strlen(buffer), 0, (sockaddr *) &_sin, sizeof _sin) < 0) {
    perror("sendto()");
    exit(errno);
  }
}

int ZClient::readServer() {
  int n = 0;
  unsigned int sinsize = sizeof _sin;

  if((n = recvfrom(_sock, _buffer, 4096 - 1, 0, (sockaddr *) &_sin, &sinsize)) < 0)
    {
      perror("recvfrom()");
      exit(errno);
    }
  _buffer[n] = 0;
  return n;
}

void	ZClient::launch() {
  std::cout << "Client listening..." << std::endl;
  while (1) {
    _timeout.tv_sec = 1;
    _timeout.tv_usec = 0;
    FD_ZERO(&_rdfs);
    FD_SET(_sock, &_rdfs);
    if (select(_sock + 1, &_rdfs, NULL, NULL, &_timeout) == -1) {
      perror("select()");
      exit(errno);
    }
    if (FD_ISSET(_sock, &_rdfs)) {
      if (readServer() == 0) {
        /* server down */
        printf("Server disconnected !\n");
        break;
      }
      /* Buffer non circulaire */
      puts(_buffer);
    }
  }
}

void	ZClient::init() {
  _sock = socket(AF_INET, SOCK_STREAM, 0);
  if (_sock == -1) {
    perror("socket()");
    exit(errno);
  }
  if ((_hostinfo = gethostbyname(_host)) == NULL) {
    fprintf (stderr, "Unknown host %s.\n", _host);
    exit(EXIT_FAILURE);
  }
  _sin.sin_addr = *(in_addr *) _hostinfo->h_addr;
  _sin.sin_port = htons(_port);
  _sin.sin_family = AF_INET;
  _timeout.tv_sec = 1;
  _timeout.tv_usec = 0;
  if ((connect(_sock, (struct sockaddr *) &_sin, sizeof(struct sockaddr))) == -1)
    exit(errno);
  printf("Client connected\n");
}

ZClient::ZClient(const char *host, int port) {
  _port = port;
  _host = host;
  _x = 0;
  _y = 0;
}

ZClient::~ZClient() {
}
