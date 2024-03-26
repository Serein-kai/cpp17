/*
3.在第1题的 print.h 头文件中，删除 print()的已有原型，再创建两个名称空间 print1 和 print2，
每个名称空间都包含函数 print(string view)。在 print.cpp 文件中实现这两个函数，
输出名称空间的名称和字符串。现在让 print_this()调用在名称空间print1中声明的函数，
让 print_that()调用在名称空间 print2 中声明的函数。运行程序，验证是否调用了正确的函数。
*/

#include "printthis.h"
#include "printthat.h"
#include "print.h"

#include <iostream>
using namespace std;

int main()
{
    print_this("使用了函数print_this()");
    print_that("使用了函数print_that()");

}
