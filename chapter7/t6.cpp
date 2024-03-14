/*
6.编写一个程序，从键盘上读取长度任意的文本字符串，再读取一个包含一个或多个字母的字符串。
输出文本字符串中以这些字母(大小写均可)开头的单词的完整列表。
*/

#include <iostream>
#include <iomanip>//使用setw函数
#include <vector>
#include <string>
using namespace std;

int main()
{
    string text;
    cout<<"请输入任意长度任意行的文本字符串，以‘*’结尾：";
    getline(std::cin, text,'*');
    string beginword;
    cout<<"请输入一个或多个字母的字符串：";
    cin>>beginword;

    vector<string> words;//存放以beginword开头的单词
    const string separetors{",;:.\"!?\n' "};//这里一定要有空格
  
    size_t start {text.find(beginword)};
    while(start!=string::npos){
        if(start==0){
            //注意substr(4,6),从4索引开始，提取6个
            //cout<<"cs1:  "<<text.substr(start,text.find_first_of(separetors,start+1)-start)<<endl;
            words.push_back(text.substr(start,text.find_first_of(separetors,start+1)-start));
            start=text.find(beginword,start+1);
            //cout<<"cs2:  "<<text.substr(start,text.find_first_of(separetors,start+1)-start)<<endl;

        }else if(text[start-1]==' '||text[start-1]==','||text[start-1]=='.'||text[start-1]=='\n'||text[start-1]=='?'){
            for(size_t i{};i<words.size();i++){
                //cout<<"cs4:  "<<i<<endl;
                if(text.substr(start,text.find_first_of(separetors,start+1)-start)==words[i]){
                    start=text.find(beginword,start+1);                    
                    break;
                }
            }
            //cout<<"cs5:  "<<text.substr(start,text.find_first_of(separetors,start+1)-start)<<endl;
            words.push_back(text.substr(start,text.find_first_of(separetors,start+1)-start));
            start=text.find(beginword,start+1);  
        }else{
            //cout<<"cs3:  "<<endl;
            start=text.find(beginword,start+1);
            continue;
        }
    }

    cout<<"words的大小为："<<words.size()<<",\n字母单词列表："<<endl;
    for(size_t i{};i<words.size();i++){
        cout<<words[i]<<endl;
    }



    return 0;
}