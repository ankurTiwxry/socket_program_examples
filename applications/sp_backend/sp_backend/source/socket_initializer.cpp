#include "../include/socket_initializer.h"

socket_initializer::socket_initializer() 
  : wpf_ui_recv_socket_fd{0}, wpf_ui_send_socket_fd{0}
{
  logger::CheckValidity("WSA Startup", WSAStartup(MAKEWORD(2, 2), &ws));
  SetupUiSockets();
}

socket_initializer::~socket_initializer() {
  WSACleanup();
}

// getters
//struct return_parameters& socket_initializer::GetWpfUiRecvSocket() {
//  ret.socket_fd = wpf_ui_recv_socket_fd;
//  ret.sock_addr = wpf_ui_recv_sockaddr;
//  return ret;
//}
//
//struct return_parameters& socket_initializer::GetWpfUiSendSocket() {
//  ret.socket_fd = wpf_ui_recv_socket_fd;
//  ret.sock_addr = wpf_ui_recv_sockaddr;
//  return ret;
//}


// wrapper functions
void socket_initializer::SetupUiSockets() {
  CreateUdpRecvSocket("WPF UI Recv Socket", wpf_ui_recv_socket_fd, 10000, wpf_ui_recv_sockaddr);
  CreateUdpSendSocket("WPF UI Send Socket", wpf_ui_send_socket_fd, 10000, "127.0.0.1", wpf_ui_send_sockaddr);
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
