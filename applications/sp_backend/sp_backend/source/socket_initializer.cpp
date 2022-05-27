#include "../include/socket_initializer.h"

socket_initializer::socket_initializer()
{
  // set up sockets array
  udp_sockets.clear();

  // wsa variable check
  logger::CheckValidity("WSA Startup", WSAStartup(MAKEWORD(2, 2), &ws));
  SetupUiSockets();
}

socket_initializer::~socket_initializer() {
  WSACleanup();
}

// wrapper functions
void socket_initializer::SetupUiSockets() {

}


void socket_initializer::CreateUdpSocket(const std::string& name, const int& port, const std::string& ip_address) {
  
  // set up udp_sockets array
  udp_sockets.clear();
  udp_sockets.reserve(udp_sockets.size() + 1);
  // SEND SOCKET
  // create socket
  int send_socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  logger::CheckValidity(name + " : send : socket()", send_socket_fd);
  // socket address structure 
  struct sockaddr_in send_socket_addr;
  send_socket_addr.sin_family = AF_INET;
  send_socket_addr.sin_port = htons(port);
  send_socket_addr.sin_addr.s_addr = inet_addr(ip_address.c_str());
  memset(&(send_socket_addr.sin_zero), 0, sizeof(sockaddr));

  // RECV SOCKET
  // create socket
  int recv_socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  logger::CheckValidity(name + " : recv : socket()", recv_socket_fd);
  // socket address structure 
  struct sockaddr_in recv_socket_addr;
  recv_socket_addr.sin_family = AF_INET;
  recv_socket_addr.sin_port = htons(port);
  recv_socket_addr.sin_addr.s_addr = inet_addr(ip_address.c_str());
  memset(&(recv_socket_addr.sin_zero), 0, sizeof(sockaddr));
  // bind socket file descriptor with socket address structure
  logger::CheckValidity(name + " : recv : bind()", bind(recv_socket_fd, (sockaddr*)&recv_socket_addr, sizeof(recv_socket_addr)));
  
  // assign values to next index of udp_sockets array
  struct udp_socket_parameters socket(send_socket_fd, send_socket_addr, recv_socket_fd, recv_socket_addr);
  udp_sockets.push_back(socket);
}

std::vector<udp_socket_parameters> socket_initializer::GetUdpSocketParameters() {
  return udp_sockets;
}
