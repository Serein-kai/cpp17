/*
2.编写一个程序，读取包含任意行的文本字符串，查找并记录文本中所有不重复的单词，
记录每个单词出现的次数。输出各单词及其出现的次数。单词及其出现的次数应在列中对齐。
单词应该左对齐，次数应该右对齐。在表格的每一行中输出 3 个单词。
*/

#include <iostream>
#include <iomanip>//使用setw函数
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> words;
    vector<size_t> numbers;
    const string separetors{",;:.\"!?\n' "};//这里一定要有空格
    string text;

    cout<<"请输入任意行的文本字符串，以*结束：\n";
    getline(std::cin, text, '*');
    
    size_t start {text.find_first_not_of(separetors)};

    while(start!=string::npos){
        size_t end=text.find_first_of(separetors,start+1);
        if (end == std::string::npos)
          end = text.length();     
        string word=text.substr(start,end-start);
        bool is_in {false};

        for(size_t i{};i<words.size();i++){
            if(word==words[i]){//如果在单词词组中找到对应的单词，数量加1,退出当前循环
                numbers[i]++;
                is_in=true;
                break;
            }
        }
        if(!is_in){//
            words.push_back(word);
            numbers.push_back(1);
        }
        start = text.find_first_not_of(separetors,end+1);
    }

    size_t max_length {};
    for (auto& word : words)
      if (max_length < word.length()) max_length = word.length();



    cout<<"你一共输入的不重复单词的数量为:"<<words.size()<<endl;
    cout<<"每个单词和对应的数量为:"<<endl;
    size_t count {}; 
    const size_t perline {3}; 
    for (size_t i {}; i < words.size(); ++i)
    {
      std::cout << std::setw(max_length) << std::left << words[i] 
	              << std::setw(4) << std::right << numbers[i] << "  ";
     if (!(++count % perline))
       std::cout << std::endl;
    }
    return 0;
}