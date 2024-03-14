/*
1.编写一个程序，读取并存储任意多个学生的名字及其成绩。计算并输出平均成绩，在一个表格中输出所有学
生的名字和成绩，每一行输出 3 个学生的名字和成绩。
*/

#include <iostream>
#include <iomanip>//使用setw函数
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> names;
    vector<double> grades;
    string input_name;
    double input_grades;
    char isjx;

    size_t maxlength {0};
    double avegrade {0};
    cout<<"请问你是否想输入学生的信息（y/n）:";
    cin>>isjx;


    while(isjx=='y'){
        cout<<"请输入学生的名字：";
        cin>>input_name;
        if(input_name.length()>maxlength){
            maxlength=input_name.length();
        }
        names.push_back(input_name);


        cout<<"请输入学生的成绩：";
        cin>>input_grades;
        avegrade+=input_grades;
        grades.push_back(input_grades);


        cout<<"请问你是否想继续输入学生的信息（y/n）？";
        cin>>isjx;
    }
    avegrade=avegrade/(names.size());
    cout<<"你输入成绩的平均值为："<<avegrade<<endl;
    cout<<"你输入的所有成绩为："<<endl;
    for(size_t i;i<names.size();i++){
        cout<<" "<<left<<setw(maxlength)<<names[i]<<left<<setw(6)<<setprecision(2)<<grades[i];
        if((i+1)%3) continue;
        cout<<endl;
    }
    return 0;
}