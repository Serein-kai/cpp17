/*编写一个程序，计算圆的面积，该程序应提示从键盘上输入圆的半径，使用公式
area=pi*radius*radius得到面积，再显示结果*/

#include <iostream>
using namespace std;
int main()
{
    float pi{3.1415926f};
    float radius{};
    float area{};

    cout<<"计算圆的面积，q其中pi的值是"<<pi<<"。请输入圆的半径："<<endl;
    cin>>radius;
    area=pi*radius*radius;
    cout<<"圆的面积为："<<area<<endl;
    return 0;
}