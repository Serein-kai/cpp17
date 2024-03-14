/*
9.修改第8 题的解决方案，使其统计调用 power(1.5,1000)时执行的乘法次数。
将每个乘法运算替换为一个辅助函数 mul0，该函数接收两个实参，输出一条消息来说明已经执行了多少次乘法运算，
然后返回两个实参的乘积。请使用至少一个静态变量。
*/

#include <iostream>
#include <iomanip>
using namespace std;


inline auto mult(long double l, long double r){
    static size_t count{};//使用静态变量
    cout <<"已经执行了 "<< ++count << " 次乘法运算。" << endl;
    return l * r;
}

long double power(double x, int n){
 
    if(n==0){
      return 1.0;
    }else if(n<0){
      return 1.0 / power(x, -n);
    }else if(n%2){
      return mult(x, power(x, n-1));
    }else{
        const auto y = power(x, n/2); 
    return mult(y, y);
    }
}

int main()
{
  cout << power(1.5, 1000) << endl;
  return 0;
}


