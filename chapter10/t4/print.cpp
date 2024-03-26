#include "print.h"
#include <iostream>


void print1::print(std::string_view s)
{
  std::cout <<"print1::"<< s << std::endl;
}
void print2::print(std::string_view s)
{
  std::cout <<"print2::"<< s << std::endl;
}
