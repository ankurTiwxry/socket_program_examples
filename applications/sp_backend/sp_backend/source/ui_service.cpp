#include "../include/ui_service.h"

// Recv Message
void ui_service::RecvMsg(unsigned int index) {
  char buffer[1024] = {0};
  int sockaddr_length = sizeof(udp_sockets[index].m_recv_sock_addr);
  recvfrom(udp_sockets[index].m_recv_socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&udp_sockets[index].m_recv_sock_addr, &sockaddr_length);
}

// Send Message
void ui_service::SendMsg(unsigned int index) {
}