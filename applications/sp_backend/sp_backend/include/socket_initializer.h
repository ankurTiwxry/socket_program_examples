#pragma once

#include "common_headers.h"
#include "logging.h"

struct udp_socket_parameters {
  int m_send_socket_fd;
  int m_recv_socket_fd;
  struct sockaddr_in m_send_sock_addr;
  struct sockaddr_in m_recv_sock_addr;

  udp_socket_parameters(int send_socket_fd, struct sockaddr_in send_sock_addr, int recv_socket_fd, struct sockaddr_in recv_sock_addr) 
  : m_send_socket_fd{send_socket_fd}, m_send_sock_addr{send_sock_addr}, m_recv_socket_fd{recv_socket_fd}, m_recv_sock_addr{recv_sock_addr} 
  {
    logger::Log("New Udp Socket Created");
  }
};

class socket_initializer 
{
public:
  socket_initializer();
  ~socket_initializer();

  // getters
  std::vector<udp_socket_parameters> GetUdpSocketParameters();

private:
  // variables
  WSAData ws;

  // dynamic list of sockets with all necessary parameters
  std::vector<udp_socket_parameters> udp_sockets;

  // functions
  // wrapper functions
  void SetupUiSockets();

  // templates to create sockets
  void CreateUdpSocket(const std::string& name, const int& port, const std::string& ip_address);

};

