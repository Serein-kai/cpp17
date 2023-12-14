/*
3.创建一个程序，从键盘上读取数组的大小，对这个数组动态分配内存，以存储浮点值。
使用指针表示法初始化数组的所有元素，使索引位置为n 的元素值是 1/(n+1)^2。
使用指针表示法计算元素的总和，对总和乘以6，输出结果的平方根。
c语言中：#include <cstdlib>,float *arry=(float*)malloc(sizeof(float)*num);
在c++中，可以使用new运算符来动态分配数组：int* dynamicArray = new int[5];
*/

#include <iostream>
#include <iomanip>//使用setprecision函数
#include <cmath>//使用sqrt()

using namespace std;

int main()
{
    int num{};
    cout<<"请输入数组的大小：";
    cin>>num;
    double *dyarry=new double[num];
    cout<<"数组中的元素为："<<endl;
    for(int i=0;i<num;i++){
        *(dyarry+i)=1.0/((i+1)*(i+1));
        cout<<setw(15)<<setprecision(10)<<dyarry[i];
    }
    cout<<endl;

    double sum{};
    for(int i=0;i<num;i++){
        sum+=*(dyarry+i);
    }
    cout<<"最终的结果为："<<sqrt(6*sum)<<endl;
    delete[] dyarry;//释放动态分配的内存

    return 0;
}