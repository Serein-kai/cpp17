// Sorting words recursively递归的排序单词
#include <iostream>
#include <iomanip>
#include <memory>//智能指针模板定义
#include <string>
#include <string_view>//提出string_view,具有固定常量的特性，即使是字符串字面量也不涉及复制。因此总是为输入参数使用std::string_view而不是const std::string&
#include <vector>//向量容器

using Words = std::vector<std::shared_ptr<std::string>>;//是自定义数据类型


void swap(Words& words, size_t first, size_t second);
void sort(Words& words);
void sort(Words& words, size_t start, size_t end);
void extract_words(Words& words, std::string_view text, std::string_view separators);
void show_words(const Words& words);
size_t max_word_length(const Words& words);

int main()
{
  Words words;
  std::string text;                                               // The string to be sorted
  const auto separators{" ,.!?\"\n"};                             // Word delimiters

  // Read the string to be searched from the keyboard
  std::cout << "Enter a string terminated by *:" << std::endl;
  getline(std::cin, text, '*');

  extract_words(words, text, separators);
  if (words.empty())
  {
    std::cout << "No words in text." << std::endl;
    return 0;
  }

  sort(words);                                                     // Sort the words 
  show_words(words);                                               // Output the words
}

//从text中提取单词，把单词的智能指针存储在words向量中。
void extract_words(Words& words, std::string_view text, std::string_view separators)
{
  size_t start{ text.find_first_not_of(separators) };                  // Start 1st word
  size_t end{};                                                      // Index for the end of a word

  while (start != std::string_view::npos)
  {
    end = text.find_first_of(separators, start + 1);                 // Find end separator
    if (end == std::string_view::npos)                               // End of text?
      end = text.length();                                         // Yes, so set to last+1
    words.push_back(std::make_shared<std::string>(text.substr(start, end - start)));
    start = text.find_first_not_of(separators, end + 1);             // Find next word
  }
}

//交换words向量中位于索引位置first和secong的元素
void swap(Words& words, size_t first, size_t second)
{
  auto temp{words[first]};
  words[first] = words[second];
  words[second] = temp;
}

// 调用包含3个参数的sort()重载函数，为了方便使用，允许使用一个vector<>实参调用sort()函数。升序
void sort(Words& words)
{
  if (!words.empty())
    sort(words, 0, words.size() - 1);
}

//使用quicksort算法对words中的一系列连续元素排序，从索引位置start到end，包含最后的end。快排
void sort(Words& words, size_t start, size_t end) 
{
  // start index must be less than end index for 2 or more elements
  if (!(start < end))//如果不小于，就停止递归函数调用
    return;                                                

  // Choose middle address to partition set
  swap(words, start, (start + end) / 2);                            // Swap middle address with start

  // Check words against chosen word，下面的实际是快排分区操作。如果当前元素小于基准值，则将其与current位置的元素交换，并将current递增。所有小于基准值的元素都被移动到了左便。
  size_t current{start};
  for (size_t i{start + 1}; i <= end; i++)
  {
    if (*words[i] < *words[start])                                  // Is word less than chosen word?
      swap(words, ++current, i);   //是交换，不是排序                                 // Yes, so swap to the left
  }

  swap(words, start, current);    //是交换，不是排序                                  // Swap chosen and last swapped words

  if (current > start) sort(words, start, current - 1);             // Sort left subset if exists
  if (end > current + 1) sort(words, current + 1, end);             // Sort right subset if exists
}

//确定words中最长单词的长度，使输出更整洁，const引用
size_t max_word_length(const Words& words)
{
  size_t max{};
  for (auto& word : words)
    if (max < word->length()) max = word->length();
  return max;
}

// 输出words中的单词，const引用
void show_words(const Words& words)
{
  const size_t field_width{max_word_length(words) + 1};
  const size_t words_per_line{8};
  std::cout << std::left << std::setw(field_width) << *words[0];     // Output the first word

  size_t words_in_line{};                                            // Words in the current line
  for (size_t i{1}; i < words.size(); ++i)
  { // Output newline when initial letter changes or after 8 per line
    if ((*words[i])[0] != (*words[i - 1])[0] || ++words_in_line == words_per_line)
    {
      words_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::setw(field_width) << *words[i];                 // Output a word
  }
  std::cout << std::endl;
}