/*
4.修改第3 题的mam()函数,只有定义了预处理标识符 DO_THIS,才能调用 print_this()。否则,就调用 print_that()。

*/

#include "printthis.h"
#include "printthat.h"
#include "print.h"

#include <iostream>
using namespace std;

#define DO_THIS//通过隐藏，可以查看

int main()
{
    /*
    #ifdef DO_THIS
    print_this("print_this");
    #endif

    #ifndef DO_THIS
    print_that("print_that");
    #endif
    */
    #ifdef DO_THIS
    print_this("print_this");
    #else
    print_that("print_that");
    #endif


    return 0;
}
