/*1.编写一个程序，提示用户输入两个整数，
然后使用 ifelse 语句输出一条消息，说明这两个整数是否相等。


*/

#include <iostream>
using namespace std;

int main()
{
    int a{};
    int b{};
    cout<<"请输入第一个整数：";
    cin>>a;
    cout<<"请输入第二个整数：";
    cin>>b;
    if(a==b)
    {
        cout<<"你输入的两个数相等！"<<endl;
    }else
    {
        cout<<"你输入的两个数不相等！"<<endl;
    }
    return 0;
}
