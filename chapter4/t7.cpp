/*7.编写一个程序，提示用户输入一个字母。使用标准库函数判断它是否为元音字母，是否为小写字母，输出结果。
最后，输出小写字母，再把其字符编码输出为一个二进制值。
提示:尽管从 C++14开始，C++支持二进制整型字面量(形如 0b11001010，参见第2章)，C标准输出函数和流不支持用二进制格式输出整数值。
它们大部分都支持十六进制和八进制格式。例如，对于 std::cout，可以使用<ios>中定义的std:hex 和 stdoct输出操作程序。
但是，要用二进制格式输出字符，就需要自己编写一些代码。不过，实现起来不会太难。
还记得吗?一个字符通常只有8 个位，可以用流一次输出其中的一个位。
可能这些二进制整型字面量也会有帮助，不然我们为什么要在这个提示的一开始就提到它们?
<cctype>中isalpha(c)检查是否是字符，islower(c)检查是否是小写字符,static_cast<int>(c)得到字符编码
<bitset>中bitset<8> binaryc(c)用于将整数表示为8位的二进制字符串

*/

#include <iostream>
#include <cctype>
#include <bitset>
using namespace std;

int main()
{
    char c{};
    cout<<"请输入一个字符：";
    cin>>c;

    if(!isalpha(c)){
        cout<<"这不是一个字母"<<endl;
        return 1;
    }

    if(!islower(c)){
        cout<<"这不是小写字符"<<endl;
    }
    int ccode=static_cast<int>(c);
    
    bitset<8> binaryc(c);
    cout<<"字符"<<c<<"的ascii码为："<<ccode<<"的二进制ascii码为："<<binaryc<<endl;

    return 0;
}
