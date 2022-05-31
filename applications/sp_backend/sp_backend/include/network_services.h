#pragma once

#include "network_utility.h"
#include "logging.h"

#include <iostream>
#include <vector>

class network_services {
public:
  network_services(const std::vector<udp_socket_parameters>& initialized_udp_sockets);
  int FindActiveSourceUi();

protected:

  // pure virtual functions
  virtual void SendMsg(unsigned int index) {}
  virtual void RecvMsg(unsigned int index) {}

  // variables
  std::vector<udp_socket_parameters> udp_sockets;


private:
  // variables
  int max_fd;
  fd_set read_fds;
  // functions
  void FindMaxFdValue();
  void SetupReadFds();
  int FindActiveSourceUiIndex();

};



