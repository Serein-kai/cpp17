/*
5. 编写一个与第 4 题等效的程序，但有以下区别:
如果在第 4 题中使用 for 循环来统计字符数，现在使用 while 循环。
如果之前使用了 while 循环，现在使用 fo循环。
在本练习题中，应该首先反转数组中的字符，
然后从左至右打印出这些字符(为了多加练习，仍然可以使用一个循环来逐个打印出字符)。


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
    while(Cstr[num]!='\0'){
        num++;
    }

    cout<<"您一共输入的字符个数为："<<num<<endl;

    cout<<"以下是你输入字符的相反顺序：";
    for(int i=0;i<num;i++){
        cout<<Cstr[num-1-i];
    }
    cout<<endl;

    return 0;
}