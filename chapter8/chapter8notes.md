# 1、错误记录
1、  string a;
    a.reserve(s.length());//预留空间，不是必不可少
    for(size_t i=0;i<s.length();i++){
        a.push_back(s[s.length()-1-i]);
       // a[i]=s[s.length()-1-i];这个语句是错误的，在c++中不能通过索引来设置string的字符，而是应该先使用push_back添加字符。
    }

2、编译好的可知性文件，在命令行输入：./myprogram arg1 arg2 arg3


# 2、字符串字面量 “hello”
字符串字面量的类型是const char[]，即字符数组

# 3、std::string_view
提出string_view的原因：

1、引用和隐式转换 
void print_it(const double&it);
int i{456}；
print_it(i);
对于引用const值支持隐式转换。编译器会在调用print_it()之前，在内存的某个位置隐式创建一个临时的double值，将转换后的int赋值给临时的double，然后把对此临时内存位置的引用传递给print_it（）
对于void find_words(const string& separators)
find_words(",l;")，之所以可以编译，是因为隐式转换

2、通过对const值的引用来传送输入实参，而不是采用按值传递，可以避免不必要的复制，并且不会修改实参。
对于复制较大的string对象，可以参数声明为const string& 

3、const string&的缺点
目的是为了避免复制，但是当传递给引用const std::string的参数时，字符串字面量还是会被复制

提出string_view,具有固定常量的特性，即使是字符串字面量也不涉及复制。

因此总是为输入参数使用std::string_view而不是const std::string&

# 4、给函数传递参数
值传递是传递副本。
引用传递数组：1可以向不引用一样，修改数组内部。2可以制定数组的第一维，知道数组的大小，并且传递不同长度的数组会导致编译器错误。3使用引用传递固定长度的数组，可以使用sizeof(),size()和基于范围的for循环，但是按值传递数组不可以.

# 5、默认实参值
函数原型：指定默认实参
void show_data(const int data[],size_t count=1,std::string_view title="Data Values",size_t width=10,size_t perLine=5);
函数定义：普通定义
void show_data(const int data[],size_t count,std::string_view title,size_t width,size_t perLine){   
}

# 6、main()函数的实参
int main(int argc,char* argv[]){
}
argc是从命令行输入的字符串实参的个数，类型是int。这个输入的时候不用管。
argv[0]，记录程序名，argv[argc]总是nullptr，一共argc+1个元素。

# 7、从函数中返回
1返回指针
不要从函数中返回在栈上分配的自动局部变量的地址
const double* smallest(const double data[],size_t count){
    return &data[index_min];
}
编译器不允许返回一个非const指针，它指向const数组的元素。因此返回类型也要指定为const。

2返回引用
不要从函数中返回自动局部变量的引用

3返回类型推断
auto getAnswer(){}

# 8、std::optional<>
能够让函数声明更加整洁、更加容易阅读.它表示一个对象可能包含一个值，或者不包含任何值（即“不存在”或“为空”）。这提供了一种明确的、类型安全的方式来表示一个值可能是可选的，而不是使用特殊值（例如指针的 nullptr 或整数的某个特定值）来表示不存在或无效的值。
std::optional<> 是C++17标准引入的一部分，并定义在 <optional> 头文件中。

1、使用 has_value() 方法可以检查 std::optional<> 是否包含值。
    optional<sieze_t> find_last(string_view string,char to_find,optional<size_t> start_index){ }；
    const suto found_b{find_last(string,'b')};
    found_b.has_value()

2、使用 value() 方法可以获取 std::optional<> 中的值，但如果在调用 value() 时 std::optional<> 为空，程序会抛出           std::bad_optional_access 异常。因此，通常在使用 value() 之前会先检查 has_value()。

3、start_index.value_or(string.size-1)，如果start_index有值，返回其值，如果没有值，返回括号里面的值。value_or() 方法返回 std::optional<> 中的值，如果 std::optional<> 为空，则返回传递给 value_or() 的默认值。
    在 std::optional<> 中，value_or() 函数用于获取 optional 对象中的值。如果 optional 对象包含了一个值（即 has_value() 返回 true），那么 value_or() 会返回这个值。如果 optional 对象为空（即不包含任何值），那么 value_or() 会返回其参数所指定的默认值。


# 9、函数重载
1、函数重载的条件：参数个数不同，参数类型不同。返回值的类型不做判断
string largest(const vextor<string>& words);和
int largest(const vector<string>& words);不能重载，因为只有返回值的类型不同

2、int*类型的参数处理起来与int[]的参数类型相同

3、不能把参数类型是data_type的函数,重载为参数类型是data_type&的函数

4、
double larger(double a,double b);
long& larger(long& a,long& b);
larger(static_cast<long>(a_int),static_cast<long>(b_int))；
这个时候调用的是第一个，因为实参是强制转换为long类型后包含相同值的临时位置。编译器不会使用临时地址来初始化对非const值的引用。

5、重载和const指针参数
对于基本类型，const int 和int相同。

对于指针参数 type*和const type*是不同的，指针所指向的值不能改变。

指向type的指针和指向type的const指针，是一样的。

# 10、递归

递归常用于实现排序和合并操作。著名Quicksort来对单词排序。
思路：首先从单词集合中任意选择一个单词，然后安排剩余单词的位置，把所有小于所选的单词放在单词的左侧，大于的放在右侧，对左右两边在进行相同的操作。
将每个单词的地址都存储为string对象的智能指针，并将指针存储到一个向量容器中。
using Words=std::vector<std::shared_ptr<std::string>>

void swap(Words& words, size_t first, size_t second);
void sort(Words& words);
void sort(Words& words, size_t start, size_t end);
void extract_words(Words& words, std::string_view text, std::string_view separators);
void show_words(const Words& words);
size_t max_word_length(const Words& words);









