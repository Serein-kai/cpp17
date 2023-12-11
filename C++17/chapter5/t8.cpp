/*8. 著名的 Fibonacci序列是一系列整数，前两个值是1，后续的值是前两个值之和。所以，
它开始于 1、1、2、3、5、8、13，等等。它不仅仅是数学方面的问题，在生物环境中也十分常见。
它与贝壳以螺旋方式生长有关，许多花的花瓣数就是这个序列中的一个数。
创建包含 93 个元素的 amay容器，将 Fibonacci序列中的前 93 个数存储在数组中，接着每行输出一个数，各个值在列中对齐。
读者是否知道我们为什么要求生成 93 个Fibomacci 数字，而不是 100 个或其他大小?
array<T,N>是类型为T的N个元素的固定序列,其中N为const size_t类型
for(auto num:fib){cout<<num<<endl;}其中fib是amay容器，可以依次输出fib中的值
对于unsigned long long类型，使用64位整数的情况，93个Fibonacci数字是可以容纳在该范围内的。
*/

#include <iostream>
#include <array>
using namespace std;

int main()
{
    const size_t n{93};
    array<unsigned long long,n> fib;
    fib[0]=fib[1]=1UL;
    for(size_t i{2};i<n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout<<"Fibonacci序列的前"<<n<<"个数字为：";
    for(auto num:fib){
        cout<<num<<endl;
    }


    return 0;
}