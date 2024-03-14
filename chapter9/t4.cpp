/*
4.编写自己的 std::size()函数系列，命名为 my_size()，使其不只可以处理固定大小的数组，还可以处理
std::vector<>和 std::array<>对象。本练习不允许使用 sizeof运算符。
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <array>

using namespace std;

template <typename T, size_t N>
size_t my_size(const T (&array)[N])
{
    return N;
}

template <typename T>
size_t my_size(const vector<T> &vector)
{
    return vector.size();
}

template <typename T, size_t N>
size_t my_size(const array<T, N> &array)
{
    return N;
}

int main()
{

    int array[]{1, 2, 3, 4, 5};
    cout << "array[]的大小为：" << my_size(array) << endl;

    cout << "字符串Always wear a smile. One size fits all.的大小：" << my_size("Always wear a smile. One size fits all.") << std::endl;

    vector<int> vector{4, 5, 6, 3};
    cout << "vector的大小：" << my_size(vector) << endl;

    std::array<int, 6> array1{4, 8, 15, 16, 23, 42};
    cout << "Size of array1 is " << my_size(array1) << endl;

    return 0;
}