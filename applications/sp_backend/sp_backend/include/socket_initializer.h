#pragma once

#include "common_headers.h"
#include "logging.h"

struct return_parameters {
  int socket_fd;
  struct sockaddr_in sockaddr;
};

class socket_initializer 
{
public:
  socket_initializer();
  ~socket_initializer();

  // getters
  struct return_parameters& GetWpfUiRecvSocket();
  struct return_parameters& GetWpfUiSendSocket();

private:
  // variables
  WSAData ws;

  // socket file descriptors
  int wpf_ui_send_socket_fd;
  int wpf_ui_recv_socket_fd;

  // sock address structs
  struct sockaddr_in wpf_ui_send_sockaddr;
  struct sockaddr_in wpf_ui_recv_sockaddr;

  // return parameters
  struct return_parameters ret;

  // functions
  // wrapper functions
  void SetupUiSockets();

  // templates to create sockets
  void CreateUdpRecvSocket(const std::string& name, int& socket_fd, const int& port, struct sockaddr_in& sock_addr);
  void CreateUdpSendSocket(const std::string& name, int& socket_fd, const int& port, const std::string& ip_address, struct sockaddr_in& sock_addr);

};

