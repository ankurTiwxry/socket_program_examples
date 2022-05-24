#pragma once

#include "common_headers.h"
#include "logging.h"

class socket_initializer 
{
public:
  socket_initializer();
  ~socket_initializer();

  // wrapper functions
  void SetupUiSockets();

  // templates to create sockets
  void CreateUdpRecvSocket(const std::string& name, int& socket_fd, const int& port, struct sockaddr_in& sock_addr);
  void CreateUdpSendSocket(const std::string& name, int& socket_fd, const int& port, const std::string& ip_address, struct sockaddr_in& sock_addr);

private:
  // variables
  WSAData ws;
  int cs_ui_socket_fd;
  int web_ui_socket_fd;

  // functions

};

