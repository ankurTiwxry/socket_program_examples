#pragma once

// Include Socket Programming libraries
#pragma comment(lib, "wsock32.lib")
#include <winsock.h>

// struct for necessary parameters
struct udp_socket_parameters {
  // NOTE: For some reason, if you define the structs after the int, the last defined one will try to write to unallocated memory
  // causes error : Heap Corruption Detected: after Normal block (#191) at <some_hex_address> CRT detected that the application wrote to memory after end of heap bugger
  struct sockaddr_in m_recv_sock_addr;
  struct sockaddr_in m_send_sock_addr;
  int m_send_socket_fd;
  int m_recv_socket_fd;
};


