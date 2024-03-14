/*7.创建一个程序，读取并存储与产品相关的任意记录序列。每个记录都包含
3 项一一整型的产品号、数量和单价，例如产品号是 1001、数量是 25、单价是S9.95。
因为现在还没有介绍复合类型，所以只需要使用 3 个不同的、类似数组的序列来代表这些记录。
程序应在单独一行上输出每个产品，包括总成本。在最后一行输出所有产品的总成本。列应对齐，输出如表 5-1 所示。


*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    vector<int> pid;
    vector<int> pnum;
    vector<double> pprice;
    vector<double> cb;
    //int num{};可以不使用，因为库中有函数

    while(true){
        cout<<"您是否想要继续输入信息（y_n）:";
        char y_n{};
        cin>>y_n;

        if(y_n=='n')
        {break;} 

        //num++;可以不使用，因为库中有函数
        cout<<"请分别输入整型的产品号、数量和单价:\n";
        int id{};
        int n{};
        int price{};
        cin>>id>>n>>price;

        pid.push_back(id);
        pnum.push_back(n);
        pprice.push_back(price);
    }

    cout<<"   产品   |"<<"   数量   |"<<"   单价   |"<<"   成本    "<<endl;
    for(int i{};i<pid.size();i++){
        cb.push_back(pnum[i]*pprice[i]);
        cout<<setw(6)<<pid[i]<<"    |"<<setw(6)<<pnum[i]<<"    |"<<setw(6)<<pprice[i]<<"    |"<<setw(6)<<cb[i]<<endl;
    }
    double price;
    for(int i{};i<cb.size();i++){
        price+=cb[i];
    }    
    cout<<"          |"<<"          |"<<"          |"<<"     "<<price<<endl;



    return 0;
}