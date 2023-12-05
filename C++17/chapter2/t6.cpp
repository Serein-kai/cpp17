/*6.这个练习针对喜欢疑难问题的读者。编写一个程序，提示用户输入两个不同的正整数，
在输出中指出哪个较大，哪个较小。如果使用第 5 章的决策语句，解决这个问题非常简单。
不能使用决策语句，使得这个问题具有一定的挑战性。
但是，使用本章学习的运算符，确实可以解决这个问题??
*/

#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cout<<"请输入第一个正整数：";
    cin>>a;
    cout<<"请输入第二个不同的正整数：";
    cin>>b;

    if(a>b){
        cout<<"第一个数比较大。"<<endl;
    }else if (a<b)
    {
        cout<<"第二个数比较大。"<<endl;
    }else{
        cout<<"您输入的是两个相同的正数。"<<endl;
    }
    //cout<<"大"<<((a+b)+abs(a-b)) / 2<<endl;
    //cout<<"小"<<(a+b-abs(a-b)) / 2 <<endl;


    return 0;
}
