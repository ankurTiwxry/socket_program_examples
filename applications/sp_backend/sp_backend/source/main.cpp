#include <iostream>
#include <string>
#include "../include/logging.h"

int main() {
  
  // logging types
  logging <int>log_int;
  logging <std::string>log_str;
    
  
  // keep console window active
  std::cin.get();
}