/*
5.修改第3 题，但如果一开始没有使用智能数组，这一次使用智能指针存储数组。
聪明的学生应该已经知道不能使用低级内存分配技术....

3.创建一个程序，从键盘上读取数组的大小，对这个数组动态分配内存，以存储浮点值。
使用指针表示法初始化数组的所有元素，使索引位置为n 的元素值是 1/(n+1)^2。
使用指针表示法计算元素的总和，对总和乘以6，输出结果的平方根。
c语言中：#include <cstdlib>,float *arry=(float*)malloc(sizeof(float)*num);
在c++中，可以使用new运算符来动态分配数组：int* dynamicArray = new int[5];

auto pdata{make_unique<double>(999.0)}//在自由存储区中个创建pdata，它包含double
变量的地址，double变量被初始化为999.0。pdata是unique_ptr指针，智能指针。

auto pdata{make_unique<double[]>(m)}//创建指向数组的唯一指针，指向自由存储区中元素类型
为double的包含n个元素的数组




*/

#include <iostream>
#include <memory>//智能指针类型
#include <cmath>//使用函数
#include <iomanip>//使用setprecision函数,setw

using namespace std;

int main()
{
    int num;
    cout<<"请输入数组元素的个数：";
    cin>>num;

    cout<<"元素中的值为："<<endl;
    auto pdata{make_unique<double[]>(num)};
    for(int i=0;i<num;i++){
        pdata[i]=1.0/((i+1)*(i+1));
        cout<<setw(15)<<setprecision(10)<<pdata[i];       
   }
   cout<<endl;
   double sum{};
   for(int i=0;i<num;i++){//使用value访问当前的元素。使用指针表示法计算元素的总和
        sum+=pdata[i];
   }
    cout<<"最终的结果为："<<sqrt(6*sum)<<endl;
    return 0;


    return 0;
}