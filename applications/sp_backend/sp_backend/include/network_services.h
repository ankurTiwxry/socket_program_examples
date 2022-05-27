#pragma once

#include "common_headers.h"
#include "logging.h"

class network_services {
public:
  network_services();

protected:


private:
  // functions
  void MainService();

  // variables
  // local socket file descriptors
  int wpf_ui_send_socket_fd;
  int wpf_ui_recv_socket_fd;

  // sock address structs
  struct sockaddr_in wpf_ui_send_sockaddr;
  struct sockaddr_in wpf_ui_recv_sockaddr;

};

class ui_services : network_services {



};

