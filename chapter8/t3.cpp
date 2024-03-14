/*
3.编写一个程序，它接收 2~4 个命令行实参。如果用少于 2 个或多于 4 个的实参调用该程序，就输出一条消息，
告诉用户应怎么做，然后退出。如果实参的个数是正确的，就输出它们，一行输出一个参数。
*/

#include <iostream>
#include <memory>//智能指针类型
#include <cmath>//使用函数
#include <iomanip>//使用setprecision函数,setw

using namespace std;

int main(int argc,char* argv[])
{
    //argc指的是命令行输入实参的个数，argv是一个指针数组，指向命令行实参，包括程序名。调用程序时使用的程序名总是在argv[0]中记录，
    //除了记录输入的参数个数，最后一个argv[argc]是空指针。
    if(argc<2||argc>4){
        cout<<"请您输入2～4个实参！"<<endl;
        return 0;
    }else{
        for(int i=0;i<argc;i++){
            cout<<argv[i+1]<<endl;
        }
    }
    return 0;
}