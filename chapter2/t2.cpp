/*使用第一题的解决方案，改进代码，使用户可以输入所需的位数，控制输出结果的精度
为了展示浮点数的精确度，可以进行双精度浮点数
输出流格式化头文件（2个）及其区别
答：iostream头文件，无参数
       iomanip头文件，有参数
*/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  const double pi {3.141592653589793238};  
  double radius {};
  int p;
  cout << "计算圆的面积，q其中pi的值是" <<pi<< endl;

  cout << "请输入半径：";
  cin >> radius;

  cout << "输出结果的精度为： ";
  cin >> p;
  
  cout << setprecision(p);
  
  const auto area = pi * radius * radius;   //auto用于推断类型

  cout << "圆的面积为 " << area << endl;
}