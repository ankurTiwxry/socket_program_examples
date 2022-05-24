#pragma once

#include "common_headers.h"
#include "logging.h"

class network_services {
public:
  network_services();
  void SetWpfUiRecvSocket(const struct return_parameters& m_socket);
  void SetWpfUiSendSocket(const struct return_parameters& m_socket);

private:
  // functions
  void MainService();

  // Udp send/recv
  void RecvUdpMessage();
  void SendUdpMessage();

  // variables

};

