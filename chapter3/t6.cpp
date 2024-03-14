/*6.最后这个练习针对喜欢疑难问题的读者。
编写一个程序，提示输入两个整数值，存储在整型变量a和b中交换a和b的值，但不使用第三个变量。
输出a和b的值。
提示:这是一个很难解决的问题。要解决这个问题，需要使用复合赋值运算符。
使用加减法
*/

#include <iostream>
using namespace std;
int main()
{
    int a{};
    int b{};
    cout<<"清输入第一个整数：";
    cin>>a;
    cout<<"清输入第二个整数：";
    cin>>b;

    a=a+b;
    b=a-b;
    a=a-b;

    cout<<"\n交换后:\n第一个数为："<<a<<"\t第二个数为："<<b<<endl;
 
    return 0;
}