/*
7.创建一个程序，将用户输入的任意长度的整数序列读入一个 sting 对象。
该序列中的数字由空格分隔，由#字符终止。换句话说，用户在输入连续两个数字的时候，不需要按 Enter 键。
接下来，使用字符串流从字符串中逐个提取所有数字，对这些数字求和，然后输出和。
在开始编写程序之前，需要先知道如何使用字符串流获取输入。
首先，创建一个 std:sting stream 对象，使其包含与给定 std::string 对象 my string 相同的字符序列，如下所示:
std::stringstream ss{ my string };
也可以将给定字符串的内容赋值给已有的字符串流:
ss.str(my string);
其次，与 std:.cin 不同，对从字符串流中提取的值有数量限制。
对于本练习，可将流转换为一个布尔值，以判断流中是否还有更多需要提取的数字。
只要流能够提供更多值，就会转换为 e。一旦读取完流中的数字，就会转换为 false。
换句话说，应该在如下形式的循环中使用字符串输入流变量 ss:
while (ss) (  Extract next number from the stream  )
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string numbers;
    cout<<"请输入任意长度的整数序列，该序列中的数字由空格分隔，由#字符终止："<<endl;
    getline(cin,numbers,'#');

    long sum{};

    stringstream ss{numbers};
    while(ss){
        int i{};
        ss>>i;
//        cout<<i<<":"<<sum<<endl;
        sum+=i;
    }
    cout<<"你输入数据的和为："<<sum<<endl;

    return 0;
}