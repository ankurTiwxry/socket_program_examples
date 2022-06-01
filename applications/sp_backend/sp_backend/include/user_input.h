#pragma once

#include "logging.h"

#include <iostream>

class user_input {

public:
  void TerminateLoop(bool* return_value) {
    if (std::cin.get() == '\n') {
      logger::Log("WARNING : Services Loop terminated!");
      *return_value = true;
    }
  }

};
