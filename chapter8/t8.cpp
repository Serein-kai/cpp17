/*
8.如果使用更加接近数学表示的方式编写 power0函数，那么 Ex8 01.cpp，特别是 Ex8 17.cpp 中编写的 power0函数
本质上是为n>0 计算 power(x,n)，如下所示:
power(x,n) = x * power(x,n-1)= x * (x * power(x,n-2))=...= x * (x * (x * ... (x * X)...)))
显然，这种方法需要n-1 次乘法操作。读者可能感到意外的是，还有另外一种更加高效的方式。
假设  n 是偶数,可知:
power(x,n) = power(x,n/2) * power(x,n/2)因为这个乘法运算的两个操作数是相等的，所以只需要计算这个值一次。
换言之，将 power(x，n)的计算缩减为power(x，n/2)，显然后者最多也只需要进行一半的乘法运算。
另外，因为现在可以递归地应用这个公式，所以需要进行的乘法运算还会更少，准确来说只有 log2(n)次。
换句话说，对于 1000 阶的数字 ，只需要 10 次乘法运算。读者是否能够运用这种思想，创建 power0函数的一个更加高效的递归版本?
可以将 Ex8 17.pp 中的程序作为基础。注意:在递归算法中经常看到这种原则的应用。在每次递归调用中，都将问题的规模缩小一半。
如果回过头思考一下，会发现我们在 Ouicksot 算法中也运用了相同的原则。这种解决方案非常常见，以至于有了自己的名称:分治法。
*/

#include <iostream>
#include <iomanip>
using namespace std;

long double power(double x, int n){
    if(n==0){
        return 1.0;
    }else if(n<0){
        return 1.0 / power(x, -n);
    }else if(n%2){//如果是奇数
        return x * power(x, n-1); 
    }else{
        const auto y = power(x, n/2); 
        return y * y;
    }
}

int main()
{
    for (int i {-3}; i <= 3; ++i){
        cout << setw(10) << power(8.0, i);
    }

    cout << endl;
    return 0;
}

