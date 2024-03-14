/*
5.将第4题中的程序推而广之，使得在决定两个字符串是否互为回文时，忽略空格。
在这个更广泛的定义中，认为 funeral和real fun 互为回文，
eleven plus two 和 twelve plus one互为回文，desperation 和 a rope ends it互为回文.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isAnagramPalindrome(const string& word1, const string& word2) {
    
    
    string sorted_word1 = word1;
    string sorted_word2 = word2;

    //清除单词中的空格信息。整个过程就是先用 std::remove 函数将字符串中的空格移动到字符串的末尾，
    //然后再用 erase 函数将末尾的空格删除，从而实现了删除字符串中所有的空格。
    sorted_word1.erase(remove(sorted_word1.begin(), sorted_word1.end(), ' '), sorted_word1.end());
    sorted_word2.erase(remove(sorted_word2.begin(), sorted_word2.end(), ' '), sorted_word2.end());

    cout<<"sorted_word1.erase:"<<sorted_word1<<endl;
    cout<<"sorted_word2.erase:"<<sorted_word2<<endl;

    // 如果两个单词的长度不同，直接返回 false
    if (sorted_word1.length() != sorted_word2.length()) {
        return false;
    }

    // 将两个单词分别排序
    sort(sorted_word1.begin(), sorted_word1.end());
    sort(sorted_word2.begin(), sorted_word2.end());

    // 如果两个排序后的单词相同，则它们是回文变位
    return sorted_word1 == sorted_word2;
}

int main() {
    string word1, word2;

    cout << "请输入第一个单词：";
    getline(std::cin, word1);

    cout << "请输入第二个单词：";
    getline(std::cin, word2);   

    // 检查两个单词是否是回文变位
    if (isAnagramPalindrome(word1, word2)) {
        cout << "单词 '" << word1 << "' 和 '" << word2 << "' 彼此互为回文。" << endl;
    } else {
        cout << "单词 '" << word1 << "' 和 '" << word2 << "' 彼此不互为回文。" << endl;
    }
    return 0;
}