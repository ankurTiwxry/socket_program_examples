#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace logger{

// Log to console window --------------------------------------------------------------------------

// Add space with a partition in console
static void LogSpace() {
  std::cout << "\n-------------------------------------------\n";
}

// Log in the same line
template<typename T>
static void LogInline(const T& msg) {
  std::cout << "LOG: " << msg;
}

// Log and move to the next line
template<typename T>
static void Log(const T& msg) {
  std::cout << msg << '\n';
}

// Check if return value is valid for socket functions ---------------------------------------------
static int CheckValidity(const std::string& function_name, const int& return_value) {
  if (return_value < 0) {
    std::cout << "\nERROR: Return value for function " << function_name << " is less than ZERO\n";
    return return_value;
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


