#include "../include/network_services.h"

network_services::network_services() {
  MainService();
}

// Public functions --------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
void network_services::SetWpfUiRecvSocket() {

}

void network_services::SetWpfUiSendSocket() {

}

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
