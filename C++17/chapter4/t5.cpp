/*5.在Ex4_06.cpp 中，在 main()函数的末尾添加一些代码，输入一条额外消息。
如果只有一只老鼠，输入这种形式的一条消息: It is a brow/white mouse。
如果有多只老鼠，则编写一条语法上正确的消息，形式如下: Of these mice,N is a/are brown mouse/mice。
如果没有老鼠，则不需要输出新消息。恰当地混合使用条件运算符和ifese 语句。

*/

#include <iostream>
using namespace std;

int main()
{
    int m{};
    int b{};
    int w{};
    cout<<"你有多少棕色老鼠？";
    cin>>b;
    cout<<"你有多少白色老鼠？";
    cin>>w;

    if(b<0||w<0){
        return 1;
    }

    m=b+w;
    cout<<"you have "<<m<<(m==1?" mouse":" mice")<<endl;

    if(m==1){
        cout<<"It is a "<<(b?"brown":"white")<<" mouse."<<endl;
    }else{
        cout<<"of these mice,"<<b<<(b == 1? " is a" : " are") 
              << " brown " << (b == 1? "mouse" : "mice") << '.' << endl;
    }

    return 0;
}
