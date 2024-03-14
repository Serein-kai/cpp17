/*
5.读者是否能够想出一种方法，验证编译器对任何给定的实参类型，只生成函数模板的一个实例?
使用Ex9_01.cpp 中的 larger()函数进行测试。
*/

#include <iostream>
#include <string>
using namespace std;

template<typename T>
T larger(T a,T b);template<typename T>
T larger(T a,T b);

int main()
{
     cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << endl;
    cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << endl;

    int big_int {17011983}, small_int {10};
    cout << "Larger of " << big_int << " and " << small_int << " is "<< larger(big_int, small_int) << endl;

    string a_string {"A"},z_string{"Z"};
    cout<<"larger of "<<a_string<<" and "<<z_string<<" is "<<larger(a_string,z_string)<<endl;

    return 0;
}

template<typename T>
T larger(T a,T b){
    static size_t count{};
    cout<<"（这个实例化模板使用了的次数："<<++count<<" ) ";
    return a>b?a:b;
}