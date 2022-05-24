#pragma once

#include "common_headers.h"
#include "logging.h"

class socket_initializer;

class network_services {
public:
  network_services(class socket_initializer& m_socket_init);
  //void SetWpfUiSendSocket(const struct return_parameters& m_socket);
  //void SetWpfUiRecvSocket(const struct return_parameters& m_socket);

private:
  // functions
  void MainService();

  // Udp send/recv
  void RecvUdpMessage();
  void SendUdpMessage();

  // variables
  // local socket file descriptors
  int wpf_ui_send_socket_fd;
  int wpf_ui_recv_socket_fd;

  // sock address structs
  struct sockaddr_in wpf_ui_send_sockaddr;
  struct sockaddr_in wpf_ui_recv_sockaddr;

};

