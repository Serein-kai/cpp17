/*3.创建一个程序，提示用户输入一个介于 1 和 100 之间的数字(允许输入小数)。
使用嵌套if语句判断该数字是否在设定的范围之内。如果是，再判断该数字是否大于、小于或等于 50。程序应输出相应的信息。


*/

#include <iostream>
using namespace std;

int main()
{
    double a{};
    cout<<"请输入一个介于1和100之间的数：";
    cin>>a;
    if(a>=1&&a<=100){
        cout<<"你输入的数在制定范围之内，";
        if(a>50){
            cout<<"并且这个数大于50。"<<endl;
        }else{
            cout<<"并且这个数小于等于50。"<<endl;
        }
    }else{
        cout<<"你输入的数不介1和100之间。"<<endl;
    }

    return 0;
}
