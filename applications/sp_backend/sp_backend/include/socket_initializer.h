#pragma once

#include "common_headers.h"
#include "logging.h"

struct udp_socket_parameters {\
  // NOTE: For some reason, if you define the structs after the int, the last defined one will try to write to unallocated memory
  // causes error : Heap Corruption Detected: after Normal block (#191) at <some_hex_address> CRT detected that the application wrote to memory after end of heap bugger
  struct sockaddr_in m_recv_sock_addr;
  struct sockaddr_in m_send_sock_addr;
  int m_send_socket_fd;
  int m_recv_socket_fd;
};

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

