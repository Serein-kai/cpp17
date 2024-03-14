/*1.创建一个程序，提示用户输入一个整数，将整数存储为 int 类型。
再对其二进制表示的所有位求反，并存储结果。
输出最初的值、取反后的值、取反后的值加 1 的结果，
这些数字用十六进制的形式输出，且放在一行上，
再以十进制的形式输出，放在另一行上。
这两行的输出值应右对齐，使用合适的字段宽度，十六进制值应有前导 0，总是显示 8 个十六进制数字。
setw()：用来控制输出字符长度
setfill('0')：设置填充字符，将0设置成填充字符

*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a{};
    cout<<"清输入一个整数：";
    cin>>a;
    int b{~a};
    int c{b+1};

    unsigned int hex_num{2*sizeof(int)};         //值的16进制的位数（8位）
    unsigned int hex_num_width{hex_num+2};       //16进制输出的时候，还要带上0x两位
    unsigned int column_width{hex_num_width+5}; //每一部分，间隔15个位置

    cout<<right<<setw(column_width)<<"value"<<setw(column_width)<<"~value"<<setw(column_width)<<"value-1"<<endl;    //setw(column_width)表示设置输出宽度

    cout<<hex<<showbase<<internal<<setfill('0')<<"     "<<setw(hex_num_width)<<a<<"     "<<setw(hex_num_width)<<b<<"     "<<setw(hex_num_width)<<c<<endl;  //setfill('0‘)表示0填充

    cout<<dec<<setfill(' ')<<right<<setw(column_width)<<a<<setw(column_width)<<b<<setw(column_width)<<c<<endl;  //right表示右对齐

    return 0;
}
