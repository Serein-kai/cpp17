/*
2.编写一个函数，要求读取字符串或字符数组作为输入,并反转它的顺序。
使用什么类型的参数最好?用main0函数测试该函数，提示用户输入一个字符串，反转其顺序，再输出反转后的字符串。
*/

#include <iostream>
#include <memory>//智能指针类型
#include <cmath>//使用函数
#include <iomanip>//使用setprecision函数,setw

using namespace std;

string fanzhuan(string s){
    //cout<<"fanzhuan函数中的s："<<s<<endl;
    string a;
    a.reserve(s.length());//预留空间，不是必不可少
    for(size_t i=0;i<s.length();i++){
        a.push_back(s[s.length()-1-i]);
       // a[i]=s[s.length()-1-i];这个语句是错误的，在c++中不能通过索引来设置string的字符，而是应该先使用push_back添加字符。
    }
    //cout<<"内部的a:"<<a<<endl;
    return a;
}


int main()
{
    string inputs {};
    cout<<"请输入一个字符串：";
    cin>>inputs;
    //cout<<"inputs:"<<inputs<<endl;
    cout<<"您输入字符串的反转字符串为：";
    cout<<fanzhuan(inputs);

    return 0;
}