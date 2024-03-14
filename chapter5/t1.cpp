/*1.编写一个程序，输出从1开始到用户输入的数字之间所有奇数的平方。


*/

#include <iostream>
using namespace std;

int main()
{
    int a{};
    cout<<"请输入数字：";
    cin>>a;
    cout<<"下面是从1到你所输入的数字之间的所有奇数的平方:"<<endl;
    for(int i=1;i<=a;i+=2){
        cout<<i<<"的平方为："<<i*i<<endl;
    }

    return 0;
}