#include "kdtrace/kdtrace.hpp"
#include <iostream>

int main(){
  int result = kdtrace::add_one(1);
  std::cout << "1 + 1 = " << result << std::endl;
}