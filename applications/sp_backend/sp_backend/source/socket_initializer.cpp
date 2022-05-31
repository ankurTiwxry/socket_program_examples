#include "../include/socket_initializer.h"

socket_initializer::socket_initializer()
{
  // set up sockets array
  udp_sockets.clear();
  udp_sockets.resize(0);
  
  // wsa variable check
  logger::CheckValidity("WSA Startup ", WSAStartup(MAKEWORD(2, 2), &ws));
  
  SetupUiSockets();
}

socket_initializer::~socket_initializer() {
  WSACleanup();
}

// wrapper functions
void socket_initializer::SetupUiSockets() {
  logger::Log("Setup UI Sockets");
  CreateUdpSocket("WPF UI 1", 25005, "127.0.0.1");
}

void socket_initializer::CreateUdpSocket(const std::string& name, const int& port, const std::string& ip_address) {
  logger::Log("Creating UDP socket to send and receive from " + name);
  
  udp_sockets.resize(udp_sockets.size() + 1); // resize array by 1
  CreateUdpRecvSocket(port+1);
  CreateUdpSendSocket(port, ip_address);
}

void socket_initializer::CreateUdpRecvSocket(const int& port) {
  int i = udp_sockets.size() - 1;
  udp_sockets[i].m_recv_socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  logger::CheckValidity("Recv : socket()", udp_sockets[i].m_recv_socket_fd);

  udp_sockets[i].m_recv_sock_addr.sin_family = AF_INET;
  udp_sockets[i].m_recv_sock_addr.sin_port = htons(port);
  udp_sockets[i].m_recv_sock_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(udp_sockets[i].m_recv_sock_addr.sin_zero), 0, sizeof(udp_sockets[i].m_recv_sock_addr)); // TODO : FIX BUG : This line is causing the issue

  logger::CheckValidity("Recv : bind()", bind(udp_sockets[i].m_recv_socket_fd, (struct sockaddr*)&udp_sockets[i].m_recv_sock_addr, sizeof(udp_sockets[i].m_recv_sock_addr)));
}

void socket_initializer::CreateUdpSendSocket(const int& port, const std::string& ip_address) {
  int i = udp_sockets.size() - 1;

  udp_sockets[i].m_send_socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  logger::CheckValidity("Send : socket()", udp_sockets[i].m_send_socket_fd);

  udp_sockets[i].m_send_sock_addr.sin_family = AF_INET;
  udp_sockets[i].m_send_sock_addr.sin_port = htons(port);
  udp_sockets[i].m_send_sock_addr.sin_addr.s_addr = inet_addr(ip_address.c_str());
  memset(&(udp_sockets[i].m_send_sock_addr.sin_zero), 0, sizeof(udp_sockets[i].m_send_sock_addr));
}



