//创建、编译、链接、执行一个程序，并在屏幕上输出文本“Hello World”

#include <iostream>
using namespace std;
/*std:: 是个名称空间标示符，C++标准库中的函数或者对象都是在命名空间std中定义的，所以我们要使用标准函数库中的函数或对象都要使用std来限定。
标准库在名字空间中被指定为std，所以在使用标准库中的函数或者对象的时候要加上std::，这样编译器就会明白我们调用的函数或者对象是名字空间std中的。*/
int main()
{
    cout<<"Hello Wordl"<<endl;
    return 0;
}
//vscode中直接点调试，或者在当前目录下终端输入g++ t1.cpp -o t1