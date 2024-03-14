/*
4.编写一个程序，提示输入两个单词，再测试它们，看看其中一个单词是否为另一个单词的回文。
通过重新排列一个单词中的字母，并只使用一次原字母,就构成了原单词的回文。
例如,listen 和 silent 彼此互为回文，但是 listens和 silent 则不然
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isAnagramPalindrome(const string& word1, const string& word2) {
    // 如果两个单词的长度不同，直接返回 false
    if (word1.length() != word2.length()) {
        return false;
    }

    // 将两个单词分别排序
    string sorted_word1 = word1;
    string sorted_word2 = word2;
    sort(sorted_word1.begin(), sorted_word1.end());
    sort(sorted_word2.begin(), sorted_word2.end());

    // 如果两个排序后的单词相同，则它们是回文变位
    return sorted_word1 == sorted_word2;
}

int main() {
    string word1, word2;

    cout << "请输入第一个单词：";
    cin >> word1;
    cout << "请输入第二个单词 ";
    cin >> word2;

    // 检查两个单词是否是回文变位
    if (isAnagramPalindrome(word1, word2)) {
        cout << "单词 '" << word1 << "' 和 '" << word2 << "' 彼此互为回文。" << endl;
    } else {
        cout << "单词 '" << word1 << "' 和 '" << word2 << "' 彼此不互为回文。" << endl;
    }

    return 0;
}
