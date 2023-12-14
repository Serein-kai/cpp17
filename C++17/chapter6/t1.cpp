/*
1.编写一个程序，声明并初始化一个数组，其中包含前 50 个奇数。使用指针表示法输出该数组中的数字，
每一行显示 10 个数字。再使用指针表示法以逆序输出这些数字。
#include <iomanip>//使用setw函数
int arry[num];*(arry+i)得到arry中第i个元素的值
*/

#include <iostream>
#include <iomanip>//使用setw函数
using namespace std;

int main()
{
    int num=50;
    int arry[num];
    for(int i=0;i<num;i++){
        arry[i]=2*i+1;
    }
    cout<<"数组中的数字为：\n";
    for(int i=0;i<num;i++){
        cout<<setw(6)<<*(arry+i);
        if((i+1)%10==0){
            cout<<endl;
        }
    }

    cout<<"数组逆序为：\n";
    for(int i=0;i<num;i++){
        cout<<setw(6)<<*(arry+(49-i));
        if((i+1)%10==0){
            cout<<endl;
        }
    }


    return 0;
}