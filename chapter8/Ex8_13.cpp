// Returning a pointer
#include <iostream>
#include <iomanip>
#include <string_view>
#include <array>                  // for std::size()

//默认实参值
void show_data(const double data[], size_t count = 1, std::string_view title = "Data Values", 
                                                      size_t width = 10, size_t perLine = 5);
const double* largest(const double data[], size_t count);
const double* smallest(const double data[], size_t count);
double* shift_range(double data[], size_t count, double delta);
double* scale_range(double data[], size_t count, double divisor);
double* normalize_range(double data[], size_t count);

int main()
{
  double samples[] {
                     11.0,  23.0,  13.0,  4.0,
                     57.0,  36.0, 317.0, 88.0,
                      9.0, 100.0, 121.0, 12.0
                   };

  const size_t count{ std::size(samples) };                // 数组的数量
  show_data(samples, count, "Original Values");            // 显示原始数据
  normalize_range(samples, count);                         // 归一
  show_data(samples, count, "Normalized Values", 12);      // 显示之后的数据
}

//类似找最小值
const double* largest(const double data[], size_t count)
{
  if (!count) return nullptr; 
  
  size_t index_max{};
  for (size_t i {1}; i < count; ++i)
    if (data[index_max] < data[i])
      index_max = i;
  
  return &data[index_max];
}

//寻找double一维数组中的最小值，返回指向数组中最小值的指针。因为参数是const类型，必须把返回值类型也制定为const，因为编译器必须返回指向const数组的元素
const double* smallest(const double data[], size_t count)
{
  if (!count) return nullptr;
  
  size_t index_min{};
  for (size_t i {1}; i < count; ++i)
    if (data[index_min] > data[i])
      index_min = i;

  return &data[index_min];
}

//通过给定量调整数组元素值
double* shift_range(double data[], size_t count, double delta)
{
  for (size_t i {}; i < count; ++i)
    data[i] += delta;
  return data;
}

//缩放数组元素
double* scale_range(double data[], size_t count, double divisor)
{
  if (!divisor) return data;                 //如果divisor为0,返回原来的数组

  for (size_t i {}; i < count; ++i)
    data[i] /= divisor;
  return data;
}

// 归一化，0-1
double* normalize_range(double data[], size_t count)
{
  return scale_range(shift_range(data, count, -(*smallest(data, count))),
    count, *largest(data, count));
    //shift_range，将数组元素减去最小值
    //缩放数组元素，第三个参数是指向数组最大元素的指针，解引用，为最大元素。
}

// 展示数据
void show_data(const double data[], size_t count, std::string_view title,
                                                  size_t width, size_t perLine)
{
  std::cout << title << std::endl;  

  for (size_t i {}; i < count; ++i)
  {
    std::cout << std::setw(width) << data[i]; 
    if ((i + 1) % perLine == 0)               
      std::cout << '\n';
  }
  std::cout << std::endl;
}

    // Newline after perLine values