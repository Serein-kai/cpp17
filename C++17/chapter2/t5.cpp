/*5.身体质量指数(Body Mass Index，BMI是体重(千克)除以身高 h(米)的平方(w/h*h))。
编写一个程序，输入体重(磅)和身高(英尺和英寸)来计算 BMI。
1千克=2.2 磅，1 英尺=0.3048 米。
1英尺=12英寸
*/
#include <iostream>
using namespace std;
int main()
{
    float w_kg,w_b,h_m,h_y1,h_y2,BMI;
    cout<<"请输入体重（磅）:";
    cin>>w_b;
    w_kg=w_b/2.2;

    cout<<"清输入身高，英尺：";
    cin>>h_y1;
    cout<<"请输入身高，英寸：";
    cin>>h_y2;
    h_m=(h_y1+h_y2/12)*0.3048;
    BMI=(w_kg/(h_m*h_m));

    cout<<"BMI="<<BMI<<endl;


    return 0;
}