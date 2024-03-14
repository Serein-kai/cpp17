/*4.使用 std:cin.getline(...)，让用户输入最多有 1000 个字符的 C 样式字符串。
使用合适的循环统计用户输入的字符数。然后，编写另外一个循环，按照相反的顺序逐个输出所有字符。
cin.getline(字符数组，大小)，从标准输入流读取一行字符串的函数。

*/

#include <iostream>
using namespace std;

int main()
{
    const int Csize{1000};
    char Cstr[Csize];
    cout<<"请输入字符串：";
    cin.getline(Cstr,Csize);
    
    int num{};
    for(;num<Csize&&Cstr[num]!='\0';++num){}
    cout<<"您一共输入的字符个数为："<<num<<endl;

    cout<<"以下是你输入字符的相反顺序：";
    for(int i=0;i<num;i++){
        cout<<Cstr[num-1-i];
    }
    cout<<endl;

    return 0;
}