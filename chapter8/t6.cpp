/*
6.编写一个程序，请求用户输入多个成绩。成绩是0-100之间的一个整数(包括0和 100 在内)。
收集了所有成绩后，程序将输出以下数据:最高的 5 个成绩，最低的 5 个成绩，平均成绩，中值成绩，
以及成绩的标准差和方差当然，需要为计算每个统计数据分别编写函数。另外，代码只能输出5 个值一次。
为了进行练习，使用数组来存储5 个极值，而不使用 vector 对象。
提示:作为一个预处理步骤，应该首先对用户输入的成绩排序:之后，编写函数来计算统计数据就简单多了。
可以通过调整 Ex8 18.cpp 中的 Quicksort 算法来处理成绩数字。
警告:一定要合理地处理用户输入的成绩数少于5 个(甚至没有输入成绩)的情况。怎么处理都可以，只要保证程序不崩溃即可。
也许可以练习使用 std::optional>来处理空成绩这样的输入?
注意:中值是出现在排序列表中间位置的值。如果成绩的个数是偶数，显然没有单独的一个中间值。此时，将中值定义为两个中间值的平均值。
计算m个成绩的中值()和标准差()的公式如下所示:
H-EC-
方差被定义为c。标准库的 cmath 头文件中定义了用于计算平方根的 std::sqrt0函数
*/

#include <iostream>
#include <iomanip>//使用setprecision函数,setw
#include <vector>
#include <cmath>//使用std::sqrt()函数
#include <string_view>//提出string_view,具有固定常量的特性，即使是字符串字面量也不涉及复制。因此总是为输入参数使用std::string_view而不是const std::string
#include <optional>//能够让函数声明更加整洁、更加容易阅读.它表示一个对象可能包含一个值，或者不包含任何值（即“不存在”或“为空”.

using namespace std;

void sort1(vector<unsigned>& numbers);

void computehighest(const vector<unsigned>& numbers,optional<unsigned>(&highest)[5]);
void computelowest(const vector<unsigned>& numbers, optional<unsigned>(&lowest)[5]);

optional<double> computeAverage(const vector<unsigned>& numbers);
optional<double> computeMedian(const vector<unsigned>& numbers);
optional<double> computeStandardDeviation(const vector<unsigned>& numbers);
optional<double> computeVariance(const vector<unsigned>& numbers);

void printNumber(std::string_view label, const optional<double>& number);
void printNumbers(std::string_view label, const optional<unsigned>(&numbers)[5]);

int main()
{
    vector<unsigned> grades;
    cout<<"请输入成绩，成绩应该在（0-100）之间，并以-1结束："<<endl;
    while(true){
        int number{};
        cin>>number;
        if(number==-1){
            break;
        }else if(number<-1||number>100){
            cout<<"你输入的数据应该在0-100之间"<<endl;
        }else{
            grades.push_back(number);
        }
    }

    // cout<<"排序之前："<<endl;
    // for(size_t i=0;i<grades.size();i++){
    //     cout<<grades[i];
    // }
    sort1(grades);
    // cout<<"\n排序之后："<<endl;
    // for(size_t i=0;i<grades.size();i++){
    //     cout<<grades[i];
    // }  
      

    optional<unsigned> highest[5]{};
    optional<unsigned> lowest[5]{};
    computehighest(grades, highest);
	computelowest(grades, lowest);

    printNumbers("Five highest grades", highest);
	printNumbers("Five lowest grades", lowest);
	printNumber("The grade average", computeAverage(grades));
	printNumber("The median grade", computeMedian(grades));
	printNumber("The standard deviation of the grades", computeStandardDeviation(grades));
	printNumber("The variance of the grades", computeVariance(grades));

    return 0;
}

//交换两个数，引用传递，使得可以更改值
void swap(vector<unsigned>& numbers,size_t first,size_t second){
    auto temp{numbers[first]};
    numbers[first]=numbers[second];
    numbers[second]=temp;
}

//递归的排序，其实是快排
void sort1(vector<unsigned>& numbers,size_t start,size_t end){
    //终止条件
    if(!(start<end)) return;

    //选择中间元素作为基准,与第一个元素进行交换
    swap(numbers,start,(start+end)/2);

    //分区操作,遍历start+1到end元素，如果当前元素小于基准元素，将当前元素与current位置的元素教化，并且current递增。最后基准值与current位置的元素交换，保证基准值在最终位置。
    size_t current{start};    // cout<<"排序之前："<<endl;
    // for(size_t i=0;i<grades.size();i++){
    //     cout<<grades[i];
    // }
    // sort1(grades);
    // cout<<"\n排序之后："<<endl;
    // for(size_t i=0;i<grades.size();i++){
    //     cout<<grades[i];
    // }   
    for(size_t i{start+1};i<=end;i++){
        if(numbers[i]<numbers[start]){
            swap(numbers,++current,i);
        }
    }
    swap(numbers,start,current);

    //递归调用
    if(current>start) sort1(numbers,start,current-1);
    if(end>current+1) sort1(numbers,current+1,end);
}

//主函数使用的时候更方便,引用非const，因为要修改
void sort1(vector<unsigned>& numbers){
    if(!numbers.empty()){
        sort1(numbers,0,numbers.size()-1);
    }
}

//得到最大的某些数据,引用传递数组：1可以像不引用一样，修改数组内部。2可以制定数组的第一维，知道数组的大小，并且传递不同长度的数组会导致编译器错误。3使用引用传递固定长度的数组，可以使用sizeof(),size()和基于范围的for循环，但是按值传递数组不可以.
void computehighest(const vector<unsigned>& numbers,optional<unsigned>(&highest)[5]){
    const auto numhighest=static_cast<int>(size(highest));//static_cast类型转换运算符，将结果转换为int类型
    for(int i=0;i<numhighest;i++){
        const int numberindex=static_cast<int>(numbers.size())-numhighest+i;
        if(numberindex>=0){
            highest[i]=numbers[numberindex];
        }else{
            highest[i]=nullopt;
        }
    }

}


void computelowest(const vector<unsigned>& numbers, optional<unsigned>(&lowest)[5]){
    for (size_t i = 0; i < size(lowest); ++i)
	{
		if (i < numbers.size()){
            lowest[i] = numbers[i];
        }else{
            lowest[i] = nullopt;
        }
	}
}

//计算平均值,使用const引用,可以避免复制
optional<double> computeAverage(const vector<unsigned>& numbers)
{
	if (numbers.empty())
		return std::nullopt;

	double average{};
	for (auto& number : numbers)
		average += number;
	return average / numbers.size();
}

//计算中间值
optional<double> computeMedian(const vector<unsigned>& numbers)
{
	if (numbers.empty())
		return std::nullopt;

	const auto numNumbers = numbers.size();
	const auto middleIndex = numNumbers / 2;
	if (numNumbers % 2)//是奇数
	{
		return numbers[middleIndex];
	}
	else
	{
		return static_cast<double>(numbers[middleIndex] + numbers[middleIndex - 1]) / 2;
	}
}

//计算标准差
optional<double> computeStandardDeviation(const vector<unsigned>& numbers)
{
	if (numbers.empty())
		return std::nullopt;

	const double average = *computeAverage(numbers);
	double sum{};
	for (auto& number : numbers)
		sum += (number - average) * (number - average);
	return sqrt(sum / numbers.size());
}

//计算方差
optional<double> computeVariance(const vector<unsigned>& numbers)
{
	if (numbers.empty())
		return std::nullopt;

	const double standardDeviation = *computeStandardDeviation(numbers);
	return standardDeviation * standardDeviation;
}

void printNumber(string_view label, const optional<double>& number)
{
	std::cout << label << ": ";

	if (number)
		cout << *number;//用于获取optional<double>类型对象number中存储的double值
	else
		cout << "n/a";//表示不适用,不可用
	cout << endl;
}

void printNumbers(string_view label, const optional<unsigned>(&numbers)[5])
{
	std::cout << label << ": ";

	for (auto& number : numbers)
	{
		if (number)
			cout << *number << ' ';
	}

	cout << endl;
}