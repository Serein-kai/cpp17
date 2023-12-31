/*如果不运行下面的代码，能不能看出这些代码的输出结果？
auto k{430u};
auto j{(k>>4)&~(~0u<<3)};
std::cout<<j<<std::endl;

*/

#include <iostream>
int main()
{
    auto k{430u};               //无符号整数，4个字节，32位，110101110
    auto j{(k>>4)&~(~0u<<3)};   
    /*（k>>4）的结果为11010,值为26。
    0u：无符号整数0,～0u为全1，～0u<<3后面三个为0,其余为1。(~0u<<3)：000...000111
    &按位与，相同为1,不同为0。最后结果为00010,最后结果为2*/
    std::cout<<j<<std::endl;
    return 0;
}