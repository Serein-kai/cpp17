/*2.编写一个程序，计算矩形搁板的一层可以容纳多少个正方形盒子，且不会出现盒子悬垂的情况。
从键盘上读取搁板的尺寸(单位是英尺)和表示盒子的边长(单位是英寸)，搁板的长度和深度使用 double 类型的变量，盒子的边长使用 int 类型的变量。
需要定义并初始化一个整型常量，用于把英尺转换为英寸(1 英尺 = 12 英寸)。计算搁板的一层可以容纳多少个盒子，并输出 long 类型的结果
static_cast<类型>类型转换运算符
*/

#include <iostream>
using namespace std;
int main()
{
    const int a{12};
    double j_l{};
    double j_d{};
    int z_b{};

    cout<<"请输入矩形搁板的长度（单位英尺）：";
    cin>>j_l;
    cout<<"请输入矩形搁板的深度（单位英尺）：";
    cin>>j_d;
    cout<<"请输入矩正方形的边长（单位英寸）：";
    cin>>z_b;

    long num{static_cast<long>(j_l*a/z_b)*static_cast<long>(j_d*a/z_b)};    //static_cast<>类型转换

    cout<<"搁板的一层可以容纳盒子数为："<<num<<endl;
    return 0;
}