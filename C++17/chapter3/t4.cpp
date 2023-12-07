/*编写一个程序，从键盘上读取4个字符，把他们放在一个整型变量中，
把这个整型变量的值显示为16进制。分解变量的4个字节，以相反的顺序输出它们，
输出低位字节。
|按位或，有1就1,全0为0。
&按位与，全1为1,有0为0。一个数&0xff，得到的是这个数后8位的内容
static_cast<int>()：强制类型转换
cout<<hex<<showbase<<num<<endl;  输出整型的16进制，其中showbase可以显示出0x

*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char a,b,c,d;
    int num;
    cout<<"请依次输入第一个字符，每个字符之间按回车："<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cout<<"a="<<static_cast<int>(a)<<endl;
    num=(a<<24)|(b<<16)|(c<<8)|(d);
    cout<<"这四个字符存放到一个整型变量中的16进制为：";
    cout<<hex<<showbase<<num<<endl;

    cout<<"分解变量的四个字符，以相反的顺序输出：";
    cout<<static_cast<char>((num)&0xff)<<static_cast<char>((num>>8)&0xff)<<static_cast<char>((num>>24)&0xff)<<static_cast<char>((num>>24)&0xff)<<endl;


    return 0;
}