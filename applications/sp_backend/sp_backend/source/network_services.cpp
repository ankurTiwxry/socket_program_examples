#include "../include/network_services.h"

network_services::network_services(class socket_initializer& m_socket_init)
{
  // Initialize all variables
  wpf_ui_send_socket_fd = m_socket_init.wpf_ui_send_socket_fd;
  wpf_ui_recv_socket_fd = m_socket_init.wpf_ui_recv_socket_fd;



  logger::Log("All variables initialized...");
  // Start services
  //MainService();
}

// Public functions --------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
//void network_services::SetWpfUiSendSocket(const struct return_parameters& m_socket) {
//  wpf_ui_send_socket_fd = m_socket.socket_fd;
//  wpf_ui_send_sockaddr = m_socket.sock_addr;
//}
//
//void network_services::SetWpfUiRecvSocket(const struct return_parameters& m_socket) {
//  wpf_ui_recv_socket_fd = m_socket.socket_fd;
//  wpf_ui_recv_sockaddr = m_socket.sock_addr;
//}

// Private functions -------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
void network_services::MainService() {
  logger::LogSpace();
  logger::Log("Starting Main Service Loop");
  logger::LogSpace();

  // infinite loop
  while (1) 
  {
    
  }
}

// Ui Service Functions ----------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
void network_services::RecvUdpMessage() {
    
}

void network_services::SendUdpMessage() {

}
