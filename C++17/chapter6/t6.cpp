/*
6.修改第 4 题，用智能指针替换任何原始指针。
*/

#include <iostream>
#include <iomanip>//使用setprecision函数,setw
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout<<"请输入数组元素的个数：";
    cin>>num;    

    auto p=make_unique<vector<double>>(num);//创建一个唯一指针，他指向一个包含num个元素double类型的数组
    for(int i=0;i<num;i++){
        (*p)[i]=1.0/((i+1)*(i+1));
        cout<<setw(15)<<setprecision(10)<<(*p)[i];       
    }
    cout<<endl;
    
    double sum{};
    for(double value:*p){//使用value访问当前的元素。使用指针表示法计算元素的总和
        sum+=value;
    }
    cout<<"最终的结果为："<<sqrt(6*sum)<<endl;
    return 0;
}