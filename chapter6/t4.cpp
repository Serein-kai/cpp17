/*
4.第三题：创建一个程序，从键盘上读取数组的大小，对这个数组动态分配内存，以存储浮点值。
使用指针表示法初始化数组的所有元素，使索引位置为n 的元素值是 1/(n+1)^2。
使用指针表示法计算元素的总和，对总和乘以6，输出结果的平方根。

修改第3 题，但使用在自由存储区中分配的 vector容器。
用超过 100000 个元素测试程序，结果有什么有趣的地方吗?
vector:
#include <vector>//包含头文件
vector<double> myvector;//创建一个空的vector
myvector.push_back(42);//向vector尾部添加元素
size_t size=myvector.size();//获取vector的大小
int element=myvector[index];//访问vector中的元素
myvector.pop_back();//删除尾部的元素
myvector.clear;//清空vector
bool isEmpty = myVector.empty();//判断是否为空
for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
    // 使用 *it 访问当前元素
}
for (int element : myVector) {
    // 使用 element 访问当前元素
}
myVector.insert(myVector.begin() + index, newValue);//插入元素到指定位置
myVector.erase(myVector.begin() + index);//删除制定位置的元素
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

    /*这个方法没有使用指针表示法，不太符合题意
    vector<double> myvector(num);//num个全是0的元素
    for(int i=0;i<num;i++){
        myvector[i]=1.0/((i+1)*(i+1));
        cout<<setw(15)<<setprecision(10)<<myvector[i];
    }
    cout<<endl;

    double sum{};
    for(int i=0;i<num;i++){
        sum+=myvector[i];
    }
    cout<<"最终的结果为："<<sqrt(6*sum)<<endl;
    */
    vector<double> myvector(num);
    vector<double> * p=&myvector;
    for(int i=0;i<num;i++){
        (*p)[i]=1.0/((i+1)*(i+1));
        cout<<setw(15)<<setprecision(10)<<myvector[i];       
    }
    cout<<endl;
    double sum{};
    for(double value:*p){//使用value访问当前的元素。使用指针表示法计算元素的总和
        sum+=value;
    }
    cout<<"最终的结果为："<<sqrt(6*sum)<<endl;
    return 0;
}