/*
6.第8 章介绍了用于字符串指针的 Quicksot算法。扩展 Ex8_18.cpp 的实现，
使其可用于任何类型的 vector(即,存在<运算符的任何类型)。
编写一个 main()函数，使用该算法对一些元素类型不同的 vector 进行排序，然后输出未排序的和排序后的元素列表。
自然，在实现这个程序时，还应该创建一个函数模板，可将任意元素类型的 vector 流输出到 std::cout。
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <iomanip> //使用setprecision函数,setw

using namespace std;

// 交换两个数，引用传递，使得可以更改值
template <typename T>
void swap(vector<T> &numbers, size_t first, size_t second)
{
    T temp{numbers[first]};
    numbers[first] = numbers[second];
    numbers[second] = temp;
}

// 递归的排序，其实是快排
template <typename T>
void sort1(vector<T> &numbers, size_t start, size_t end)
{
    // 终止条件
    if (!(start < end))
        return;

    // 选择中间元素作为基准,与第一个元素进行交换
    swap(numbers, start, (start + end) / 2);

    // 分区操作,遍历start+1到end元素，如果当前元素小于基准元素，将当前元素与current位置的元素教化，并且current递增。最后基准值与current位置的元素交换，保证基准值在最终位置。
    size_t current{start}; // cout<<"排序之前："<<endl;
    // for(size_t i=0;i<grades.size();i++){
    //     cout<<grades[i];
    // }
    // sort1(grades);
    // cout<<"\n排序之后："<<endl;
    // for(size_t i=0;i<grades.size();i++){
    //     cout<<grades[i];
    // }
    for (size_t i{start + 1}; i <= end; i++)
    {
        if (numbers[i] < numbers[start])
        {
            swap(numbers, ++current, i);
        }
    }
    swap(numbers, start, current);

    // 递归调用
    if (current > start)
        sort1(numbers, start, current - 1);
    if (end > current + 1)
        sort1(numbers, current + 1, end);
}

// 主函数使用的时候更方便,引用非const，因为要修改
template <typename T>
void sort1(vector<T> &numbers)
{
    if (!numbers.empty())
    {
        sort1(numbers, 0, numbers.size() - 1);
    }
}

template <typename T>
void print(const vector<T> &numbers, size_t width = 5)
{
    for (auto number : numbers)
    {
        cout << setw(width) << number;
        cout <<",";
    }
    cout<<endl;
}

int main()
{
    vector<int> numbers{-2, 4, -5, 6, 10, -40, 56, 4, 67, 45};
    cout<<"整数排序之前：";
    print(numbers);
    sort1(numbers);
    cout << "整数排序之后：";
    print(numbers);

    
    vector<char> letters{'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f'};
    cout << "\n字符排序之前：";
    print(letters, 2);
    sort1(letters);
    cout << "字符排序之后：";
    print(letters, 2);

    cout << "\ndouble型vector排序之前：";
    vector<double> values{-2.5, 1.4, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0};
    print(values, 10);
    sort1(values);
    cout << "\ndouble型vector排序之后：";
    print(values, 10);

    return 0;
}
