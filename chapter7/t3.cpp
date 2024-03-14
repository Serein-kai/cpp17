/*
3.编写一个程序，从键盘上读取长度任意的文本字符串，再提示输入要在文本字符串中查找的单词。
程序应查找出现在文本字符串中的所有该单词，不考虑大小写，再用与单词中字符个数相同的星号替换该单词，
然后输出新的文本字符串。注意必须替换整个单词。
例如，如果用户输入了字符串"Our house is at your disposal"，要查找的单词是 our，
则得到的字符串应是"*** house is at your disposal."，而不是"*** house is at y*** disposal."。
*/

#include <iostream>
#include <iomanip>//使用setw函数
#include <vector>
#include <string>
#include <algorithm> // ransform
#include <cctype>    // tolower
using namespace std;

int main()
{
    vector<string> words;
    const string separetors{",;:.\"!?\n' "};//这里一定要有空格

    string text;
    cout<<"请输入任意长度任意行的文本字符串，以‘*’结尾：";
    getline(std::cin, text,'*');
    std::transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c){ return std::tolower(c); });//把text中的大写都改称小写

    string word;
    cout<<"请输入要在文本字符串中查找的单词：";
    cin>>word;//替换成word.length个*
    std::transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c){ return std::tolower(c); });//把word中的大写都改称小写

    size_t start {text.find(word)};
    while(start!=string::npos){
        if(start==0){//如果是第一个，那肯定就是
            text.replace(start,word.length(),word.length(),'*');
            start=text.find(word,start+word.length());
        }else if(text[start-1]!=' '||text[start-1]!=','||text[start-1]!='.'){//如果前面不是这些的话，说明是另外一个单词的组成部分，跳过
            start=text.find(word,start+1);
            continue;
        }else{//不是第一个，并且前面是空格，逗号或这句号，可以替换。
            text.replace(start,word.length(),word.length(),'*');
            start=text.find(word,start+word.length());
        }

    }

    cout<<"替换后的字符为:"<<text;
    return 0;
}