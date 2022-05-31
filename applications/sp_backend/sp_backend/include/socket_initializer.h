#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "network_utility.h"
#include "logging.h"



class socket_initializer 
{
public:
  socket_initializer();
  ~socket_initializer();

  // getters
  std::vector<udp_socket_parameters> GetUdpSocketParameters() {
    return udp_sockets; 
  }

private:
  // variables
  WSAData ws;
  
  // dynamic list of udp sockets with all necessary parameters
  std::vector<udp_socket_parameters> udp_sockets;

  // functions
  // wrapper functions
  void SetupUiSockets();

  // templates to create sockets
  void CreateUdpSocket(const std::string& name, const int& port, const std::string& ip_address);
  void CreateUdpSendSocket(const int& port, const std::string& ip_address);
  void CreateUdpRecvSocket(const int& port);
};

