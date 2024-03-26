/*
2.修改第 1 题的程序，使 print()函数使用全局整型变量来计算它被调用的次数。在 main()调用 print_this()和
print_that()后，输出这个变量的值。
*/

#include "printthis.h"
#include "printthat.h"
#include "print.h"//call_count
#include <iostream>
using namespace std;

int main()
{
  print_this("使用了函数print_this()");
  print_that("使用了函数print_that().");
  cout << "print()被调用的次数为：" << call_count<< endl;
}