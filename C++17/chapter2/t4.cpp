/*4.在生日那天，你得到一个卷尺和一台可以确定角度的仪器，例如测量水平线和树高之间的夹角。
如果知道自己与树之间的距离 d以及眼睛平视量角器的高度 h，
就可以用公式 h+d*tan(angle)计算出树的高度。
创建一个程序,从键盘上输入 h(单位是英寸)、d(单位是英尺和英寸)和 ngle(单位是度)，
输出树的高度(单位是英尺)。
简单提示: 1 英尺等于 12 英寸。
*/

#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926

int main()
{
    float h;
    float d_1,d_2;
    float ngle;
    float tree_h;
    cout<<"请输入h，单位是英寸:";
    cin>>h;

    cout<<"请输入d的英尺:";
    cin>>d_1;

    cout<<"请输入d的英寸:";
    cin>>d_2;

    cout<<"清输入ngle，单位是度:";
    cin>>ngle;
    
    tree_h=h+(d_1*12+d_2)*tan(ngle*PI/180);
    tree_h=tree_h/12;
    cout<<"树高为："<<tree_h<<"英尺。"<<endl;

    return 0;
}