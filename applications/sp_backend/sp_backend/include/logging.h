#pragma once

#include <iostream>
#include <string>
#include <fstream>

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

  // log in console window 
  void Log(const T& msg) {
    std::cout << msg << std::endl;
  }

  // log to file
  void LogToFile(const T& msg) {
    output_file << msg << std::endl;
    std::cout << "LOG: " << msg << std::endl;
  }


private:
  std::ofstream output_file;

};

