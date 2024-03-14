/*
2.将 Ex9 01.cpp 中 main()函数的最后几行修改如下:
const auto a_string = "A"，z_string = "z";
std::cout << "Larger of " << a_string << " and " << z_string<<" is " << larger(a_string, z_string) << std::endl;
如果现在运行程序，很可能会得到如下输出(如果输出不同，则尝试改变a_sting 和z_sting 的声明顺序:
Larger of 1.5 and 2.5 is 2.5
Larger of 3.5 and 4.5 is 4.5
Larger of 17011983 and 10 is 17011983
Larger of A and Z is A
为什么"A"比"Z"大?读者能够解释这里发生了什么问题吗? 是否能够修复问题?
提示:要比较两个字符数组，可以先把它们转换为另外一种字符串表示形式。
*/

#include <iostream>
#include <string>
using namespace std;
template<typename T> T larger(T a,T b);
template<> 
const char* larger(const char* a,const char* b);


int main()
{
    cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << endl;
    cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << endl;

    int big_int {17011983}, small_int {10};
    cout << "Larger of " << big_int << " and " << small_int << " is "<< larger(big_int, small_int) << endl;

    // string a_string {"A"},z_string{"Z"};
    // cout<<"larger of "<<a_string<<" and "<<z_string<<" is "<<larger(a_string,z_string)<<endl;

    //a_string和z_string被声明为const char *类型，因此函数内部比较的是指针的大小，而不是指针所指的值的大小。
    const auto a_string="A",z_string="Z";
    cout<<"error::larger of "<<a_string<<" and "<<z_string<<" is "<<larger(a_string,z_string)<<endl;

    //解决办法是写一个特定的函数模板


    return 0;
}

template<typename T> 
T larger(T a,T b){
    return a>b?a:b;
}

template<> 
const char* larger(const char* a,const char* b){
    //比较两个字符数组，可以先把他们转换成字符串表示形式
    return string_view{a}>string_view{b}?a:b;
}