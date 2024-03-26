#include "print.h"
#include <iostream>

// 这是定义，并初始化为0
int call_count {};

void print(std::string_view s)
{
  ++call_count;
  std::cout << s << std::endl;
}