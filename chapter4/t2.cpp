/*2.编写一个程序，提示用户输入两个整数，但是拒绝任何负数或 0。
然后，检查其中一个正数是否是另一个正数的倍数。例如，63 是1、3、7、9、21 或 63 的倍数。
注意，应该允许用户以任意顺序输入数字。即，用户先输入大数还是小数并不重要，程序在两种情况下都应该正确工作!


*/

#include <iostream>
using namespace std;

int main()
{
    int a{};
    int b{};
    cout<<"请输入两个整数（按回车）："<<endl;
    cin>>a>>b;
    if((a<=0)&&(b<<0)){
        cout<<"不符合要求！您输入的两个数有负数或者0！"<<endl;
    }else{
        if(a>=b){
            if(a%b){
                cout<<"其中一个数不是另外一个数的倍数！"<<endl;
            }else{
                cout<<"其中一个数是另外一个数的倍数！"<<endl;
            }
        }else{
            if(b%a){
                cout<<"其中一个数不是另外一个数的倍数！"<<endl;
            }else{
                cout<<"其中一个数是另外一个数的倍数！"<<endl;
            }
        }
    }

    return 0;
}
