/*
1.在C++17 中，标准库的 algorithm 头文件提供了方便的 std::clamp()函数模板。
表达式 clamp(a,b,c)用来将值a夹紧到闭区间[b,c]。即，如果a 小于b，则表达式的结果将为b;
如果 a 大于c，则表达式的结果将为c : 否则，如果 a位于[b.c]区间内，clamp0将返回 a。
编写自己的my_clamp()函数模板，并用一个小的测试程序测试该函数模板。
*/

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

template <typename T> 
 T my_clamp(T a, T b,T c);

int main()
{
    int int_a=9,int_b=11,int_c=19;
    cout<<"int_result:"<<my_clamp<int>(int_a,int_b,int_c)<<endl;
    double d_a=9.32,d_b=3.23,d_c=9.88;
    cout<<"double_result:"<<my_clamp<double>(d_a,d_b,d_c);
    return 0;
}

template <typename T> 
 T my_clamp(T a, T b,T c){
    if(a<b){
        return b;
    }else if(a>c){
        return c;
    }else{
        return a;
    }
}

