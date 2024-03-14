/*
8.重复第7题，但是这一次，使用户逐个输入数字，在每次输入后需要 Enter 键。
应该将输入作为一个独立字符串的序列收集起来(为了进行练习，不直接把它们作为整数收集起来)，
然后连接为一个字符串。输入仍然由#字符终止。而且，这一次不允许使用字符串流从结果字符串中提取数字。
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nums;
    cout<<"请逐个输入数字，每次输入后按enter键，由#终止："<<endl;
    while(true){
        string num;
        cin>>num;
        if(num=="#")break;
        nums+=num+' '; 
    }
    //cout<<nums<<endl;
    long sum{};
    size_t first{};
    while(true){
        size_t end=nums.find(' ',first);
        if(end==string::npos) break;
        int i=stoi(nums.substr(first,end-first));
        //cout<<i<<":"<<sum<<endl;
        sum+=i;
        first=end+1;
    }
    cout<<"你输入数据的和为："<<sum<<endl;

    return 0;
}