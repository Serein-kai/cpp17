/*
1.编写一个程序，调用两个函数 print_this(std::string_view)和 print_that(std:string_view),
这两个函数又调用第三个函数 print(std:sting_view)，输出传送给它的字符串。
在单独的源文件中实现这 3 个函数和 man()函数，并创建3个头文件，分别包含 print this()、print that和 print()的原型
*/

#include "printthat.h"
#include "printthis.h"
/// @brief 
/// @return 
int main()
{
    printthat("printthat");
    printthis("printthis");

    //return 0;
}//原本的问题：当有多个cpp文件的时候，无法编译，问题在于tasks文件有个语句错误
