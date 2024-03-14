/*6.创建一个 vector 容器，其元素包含从 
1 开始到用户输入的任意上界的整数。输出向量中不是 7 或 13 的倍数的元素值。
在每一行上输出 10 个值，各个值在列中对齐。
vector<T>容器存储一系列类型为T的元素，添加元素时，该容器会根据需要动态提高其容量。
continue：用于跳过当前循环迭代中余下的代码，直接进入下一次迭代。
break：用于立即退出循环，不再执行循环中剩余的代码。
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    cout<<"最大上界是：";
    unsigned max{};
    cin>>max;

    vector<unsigned> a;
    for(unsigned i{1};i<=max;i++){
        a.push_back(i);
    }
    int num{};  //已经输出的数量
    int leishu{10};

    for(int i{1};i<=leishu;i++){
        cout<<setw(4)<<i<<"列";
    }
    cout<<endl;

    for(auto aa:a){     //aa 都将被自动推断为容器中的元素类型，并且循环会依次遍历容器中的每个元素
    if(aa%7==0||aa%13==0){
        continue;
    }
    cout<<setw(6)<<aa;
    if((++num)%leishu==0){cout<<endl;}
    }
    cout<<endl;


    return 0;
}