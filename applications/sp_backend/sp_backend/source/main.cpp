#include "../include/logging.h"
#include "../include/socket_initializer.h"
#include "../include/network_services.h"


int main() 
{
  socket_initializer socket_init;
  network_services parent_service(socket_init.GetUdpSocketParameters());

}

