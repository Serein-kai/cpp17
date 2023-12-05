/*3.创建一个程序，把英寸统一转换为英尺和英寸。
简单提示: 1 英尺等于 12 英寸。
例如，输入 77 英寸，程序就应生成6 英尺5 英寸的结果。
提示用户输入一个单位是英寸的整数值，再进行转换，输出结果。*/
#include <iostream>
using namespace std;
int main()
{
    const int a {12};
    long inches {};

    cout << "清输入英寸：";
    cin >> inches;

    const long feet {inches / a};
    const long f_inches {inches % a};

    cout  << inches << " = "<< feet << "英尺 " << f_inches << "英寸" << endl;

    return 0;
}