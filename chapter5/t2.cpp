/*2.
创建一个程序，使用 while 循环累加用户输入的数字(个数随机)的整数和。
在每次迭代后，询问用户是否完成数字的输入。
最后输出所有数字的总和和浮点数类型的平均值。
std::setprecision(6) 用于设置输出流的浮点数精度为小数点后6位。<iomanip>库中
std::fixed 用于确保以固定点格式输出

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int sum{};
    int num{};

    while(1){
        cout<<"请输入整数：";
        int n;
        cin>>n;
        sum+=n;
        num++;

        char y_n{};
        cout<<"你想要继续输入数据吗(y/n)：";
        cin>>y_n;

        if(y_n=='n'){
            break;
        }
    }
    cout<<"所有数的总和为："<<sum<<endl<<"平均数为:"
    <<fixed<<setprecision(6)<<(static_cast<double>(sum)/num)<<endl;

    return 0;
}
