/*4.创建一个函数plus()，它把两个数值加在一起，返回它们的和。提供处理 int、double 和 sting 类型的重载版本，测试它们是否能处理下面的调用:
const int n {plus (3, 4)};
const double d {plus (3.2,4.2) };
const string s {plus ("he","llo")};
const string sl {"aaa"};
const string s2 {"bbb"};
const string s3 {plus(s1, s2)};
为什么下面的调用不工作?
const auto d {plus(3， 4.2)1: 
*/


#include <iostream>
#include <memory>//智能指针类型
#include <cmath>//使用函数
#include <iomanip>//使用setprecision函数,setw
#include <string>

using namespace std;

int plus1(int a,int b);
double plus1(double a,double b);
string plus1(string_view a,string_view b);//提出string_view,具有固定常量的特性，即使是字符串字面量也不涉及复制。

int main()
{
    const int n {plus1(3,4)};
    cout<<"n=plus1(3,4)="<<n<<endl;
    const double d {plus1(3.2,4.2) };
    cout<<"d=plus1(3.2,4.2)="<<d<<endl;    
    const string s {plus1("he","llo")};
    cout<<"s=plus1(\"he\",\"llo\")="<<s<<endl;  
    const string s1 {"aaa"};
    const string s2 {"bbb"};
    const string s3 {plus1(s1, s2)};
    cout<<"s3=plus1(s1,s2)="<<s3<<endl;  

    //const auto d {plus1(3，4.2); 无法运行，因为函数重载无法选择。

    return 0;
}
int plus1(int a,int b){
    //cout<<"调用了int plus(int a,int b)"<<endl;
    return a+b;
}

double plus1(double a,double b){
    //cout<<"调用了double plus(double a,double b)"<<endl;
    return a+b;
}

string plus1(string_view a,string_view b){
    //cout<<"调用了string plus(string a,string b)"<<endl;
    return string(a)+string(b);
}
