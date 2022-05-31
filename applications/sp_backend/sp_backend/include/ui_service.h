#pragma once

#include "network_services.h"

class ui_service : public network_services {

public:
  void SendMsg(unsigned int index);
  void RecvMsg(unsigned int index);

private:
  

};

