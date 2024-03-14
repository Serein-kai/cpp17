/*
2.修改第1题，在第一次输出数组的值时，不使用循环计数器访问数组值，而是使用指针递增(使用++运算符)遍历数组。
之后，使用指针递减(使用--运算符)以逆序遍历数组。
int *point=arry;*point++使用指针读取数组中的元素
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
    int *point=arry;


    cout<<"数组中的数字为：\n";
    for(int i=0;i<num;i++){
        cout<<setw(6)<<*point++;
        if((i+1)%10==0){
            cout<<endl;
        }
    }


    cout<<"数组逆序为：\n";
    for(int i=0;i<num;i++){
        cout<<setw(6)<<*--point;
        if((i+1)%10==0){
            cout<<endl;
        }
    }


    return 0;
}