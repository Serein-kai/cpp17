/*
3.编写一个函数模板 plus()，使其可接收两个不同类型的实参，返回这两个实参的和。然后，确保可以使用plus()
将两个给定指针指向的值相加。
附加题:读者是否能够修改plus()，使其也能够将两个字符串字面量连接起来? 警告: 这可能没有想象中那样简单。
*/

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

template <typename T>
T plus1(const T a, const T b)
{
    cout << "调用了原本的";
    return a + b;
}

// 模板重载
template <typename T>
T plus1(T *a, T *b)
{
    cout << "调用了模板重载";
    return *a + *b;
}

// 函数重载
string plus1(const char *a, const char *b)
{
    cout << "调用了函数重载";
    return string{a} + string{b};
}

int main()
{
    int n{plus1(3, 5)};
    cout << "plus1(3,5)=" << n << endl;

    string s1{"aaa"};
    string s2{"bbb"};
    auto s3 = plus1(s1, s2);
    cout << "plus1(s1,s2)=" << s3 << endl;

    double a = 1.2, b = 2.2;
    auto c = plus1(&a, &b);
    cout << "plus1(&a,&b)=" << c << endl;

    string s{plus1("he", "llo")};
    cout << "plus(\"he\", \"llo\")=" << s << endl;

    return 0;
}