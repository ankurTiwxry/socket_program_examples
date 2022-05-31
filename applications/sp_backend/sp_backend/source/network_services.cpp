#include "../include/network_services.h"

network_services::network_services(const std::vector<udp_socket_parameters>& initialized_udp_sockets) {
  // get all varaibles here
  udp_sockets = initialized_udp_sockets;
}

// public functions
int network_services::FindActiveSourceUi() {
  FindMaxFdValue();
  SetupReadFds();
  return FindActiveSourceUiIndex();
}

// private functions

void network_services::FindMaxFdValue() {
  for (unsigned int i = 0; i < udp_sockets.size() - 1; i++) {
    max_fd = max(udp_sockets[i].m_recv_socket_fd, udp_sockets[i + 1].m_recv_socket_fd);
  }
}

void network_services::SetupReadFds() {
  // set file descriptors for reading
  FD_ZERO(&read_fds);
  for (unsigned int i = 0; i < udp_sockets.size(); i++) {
    FD_SET(udp_sockets[i].m_recv_socket_fd, &read_fds);
  }
}

int network_services::FindActiveSourceUiIndex() {
  // select active file descriptor which can read
  select(max_fd + 1, &read_fds, NULL, NULL, NULL);
  // find index of Ui socket that is active
  for (unsigned int i = 0; i < udp_sockets.size(); i++) {
    if (FD_ISSET(udp_sockets[i].m_recv_socket_fd, &read_fds))
      return i;
  }
}






