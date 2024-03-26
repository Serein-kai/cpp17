#ifndef PRINT_H
#define PRINT_H
#include <string_view>
extern int call_count;//这个是声明，告诉编译器这个变量在其他文件中已经定义。
//如果你在头文件中只是简单地声明一个变量但不加 extern，而且该头文件被多个源文件包含，那么在链接阶段就会出现变量重定义的错误。
void print(std::string_view s);

#endif