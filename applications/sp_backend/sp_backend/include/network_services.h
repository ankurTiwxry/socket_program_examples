#pragma once

#include "network_utility.h"
#include "logging.h"

#include <iostream>
#include <vector>

class network_services {
public:
  network_services(const std::vector<udp_socket_parameters>& initialized_udp_sockets);
  void MainService();

protected:

  // pure virtual functions
  virtual void SendMsg() {}
  virtual void RecvMsg() {}

  // variables
  std::vector<udp_socket_parameters> udp_sockets;


private:
  // variables
  int max_fd;
  fd_set read_fds;
  // functions
  void FindMaxFdValue();
  void SetupReadFds();
  int FindMsgSource();

};



