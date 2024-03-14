/*3.下面的程序有几处编译错误。请指出这些错误并更正，使程序能正确编译并运行
include <iostream>
Int main()
{
    std:cout << "Hello World" << std:endl
}
*/
//有五处错误 #include ，i大写，std：：，第一句之后；号,要有返回值

#include <iostream>
int main()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}