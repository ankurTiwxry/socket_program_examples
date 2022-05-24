#include "../include/logging.h"
#include "../include/socket_initializer.h"
#include "../include/network_services.h"

int main() 
{
  socket_initializer socket_init;
  network_services service(socket_init);

  // passing variables around - there are multiple ways to do this
  /*service.SetWpfUiRecvSocket(socket_init.GetWpfUiRecvSocket());
  service.SetWpfUiSendSocket(socket_init.GetWpfUiSendSocket());
*/
}