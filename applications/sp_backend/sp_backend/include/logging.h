#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace logger{

// Log to console window
template<typename T>
static void LogStat(const T& msg) {
  std::cout << "LOG: " << msg << std::endl;
}

// Check if return value is valid for socket functions
static int CheckValidity(const std::string& function_name, const int& return_value) {
  if (return_value < 0) {
    std::cout << "\nERROR: Return value for function " << function_name << " is less than ZERO\n";
    return -1;
  }
  return 0;
}

// ---------------------------------------------------------------------------------------------------

// LOG to file Class definition
template<typename T>
class logging {
public:

  // ctor
  logging() {
    output_file.open("../log.txt");
  }

  // dtor
  ~logging() {
    output_file.close();
  }

  void LogToFile(const T& msg) {
    std::cout << "LOG: " << msg << std::endl;
    output_file << "LOG: " << msg << std::endl;
  }

private:
  std::ofstream output_file;
};



}


