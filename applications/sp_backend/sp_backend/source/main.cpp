#include "../include/logging.h"
#include "../include/socket_initializer.h"
#include "../include/network_services.h"
#include "../include/ui_service.h"
#include "../include/user_input.h"

#include <iostream>
#include <thread>


static bool m_break_condition = false;

// services loop
void ServicesLooper(network_services& nws) {
  logger::LogSpace();
  logger::Log("Starting services...");

  while (1) {
    // terminate loop condition check
    if (m_break_condition) {
      break;
    }
    // Prepare console display 
    logger::LogSpace();
    logger::Log("Waiting for a new command...");

    // Perform tasks
    
  }
}

// main
int main() 
{
  user_input input;
  socket_initializer socket_init;
  network_services parent_service(socket_init.GetUdpSocketParameters());

  // create threads
  std::thread service_thread = std::thread(ServicesLooper, std::ref(parent_service));
  std::thread user_input_thread = std::thread(&user_input::TerminateLoop, std::ref(input), &m_break_condition);

  // synchronize threads
  service_thread.join();
  user_input_thread.join();

  return 0;

}

// function definitions

