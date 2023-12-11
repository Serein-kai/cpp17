/*3.创建一个程序，使用 dowhile 循环计算用户在一行上输入的非空白字符的个数。
在第一次遇到输入中的#字符时，停止计数。
#include <cctype>//使用函数isspace()


*/

#include <iostream>
#include <cctype>//使用函数isspace()
using namespace std;

int main()
{
    char c{};
    int count{};
    cout<<"请输入一行字符，以#结尾：";
    do{

        cin>>c;
        if(!isspace(c)) //检查是否为空白字符，如果不是，count+1
        {
            count++;
        }
    }while(c!='#');
    --count;
    cout<<"你一共输入的非空白字符个数为："<<count<<endl;

    return 0;
}