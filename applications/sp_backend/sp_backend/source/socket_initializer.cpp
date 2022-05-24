#include "../include/socket_initializer.h"

socket_initializer::socket_initializer() 
  : cs_ui_socket_fd{0}, web_ui_socket_fd{0}
{
  logger::CheckValidity("WSA Startup", WSAStartup(MAKEWORD(2, 2), &ws));
  SetupUiSockets();
}

socket_initializer::~socket_initializer() {
  WSACleanup();
}

// wrapper functions
void socket_initializer::SetupUiSockets() {

}

// create udp sockets template ----------------------------------------------------------------------------------------------------------
void socket_initializer::CreateUdpRecvSocket(const std::string& name, int& socket_fd, const int& port, struct sockaddr_in& sock_addr) {
  
  // create socket file descriptor
  socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  logger::CheckValidity(name + " : socket()", socket_fd);

  // socket address struct values
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(port);
  sock_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(sock_addr.sin_zero), 0, sizeof(sockaddr));

  // bind to socket file descriptor with socket address struct
  logger::CheckValidity(name + " : Bind()", bind(socket_fd, (sockaddr*)&sock_addr, sizeof(sock_addr)));
}

void socket_initializer::CreateUdpSendSocket(const std::string& name, int& socket_fd, const int&port, const std::string& ip_address, struct sockaddr_in& sock_addr) {

  // create socket file descriptor
  socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  logger::CheckValidity(name + " : socket()", socket_fd);

  // socket address struct values
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(port);
  sock_addr.sin_addr.s_addr = inet_addr(ip_address.c_str());
  memset(&(sock_addr.sin_zero), 0, sizeof(sockaddr));
}
