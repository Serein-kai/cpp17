/*
5.定义一个函数，检查给定数字是否是质数。不要求检查质数的代码很高效:读者能够想到的任何算法都可接受。
这里重新说明一下，质数是比1大的自然数，除了1 和自身之外，不能被其他正数整除。
编写另外一个函数,使其生成一个 vector>，该vetor>中包含从一个数字开始，小于或等于另一个数字的所有自然数。默认情况下应该从1开始。
创建第三个函数，它接收一个数字 vector作为参数，输出另外一个 vecor，其中包含在输入中找到的所有质数。
使用这三个函数创建一个程序，输出小于或等于用户选择的数字的所有质数(例如，每行输出15个质数)。
注意:原则上，要输出这些质数，并不需要任何 vector 对象:显然，添加这些函数只是为了帮助读者多加练
*/

#include <iostream>
#include <iomanip>//使用setprecision函数,setw
#include <vector>
#include <cmath>//使用sqrt()

using namespace std;

bool ifprime(unsigned number);//检查给定数字是否是质数
vector<unsigned> generateNumbers(unsigned to, unsigned from = 1);//生成一个vector，从一个数字开始(默认1),小于或等于另一个数字的所有自然数
vector<unsigned> filterPrimeNumbers(const vector<unsigned>& numbers);//输出vector,包含在其中的所有质数。使用引用，可以不用复制



int main()
{
	unsigned number{};
	cout<<"请你输入一个数字：";
	cin>>number;

	auto numbers = generateNumbers(number);//生成自然数
	auto primes = filterPrimeNumbers(numbers);//生成质数
	
	unsigned count{};
	for (auto& prime : primes)
	{
		cout << setw(6) << prime;
		if (++count % 15 == 0)
			cout << '\n';
	}
	
	cout << endl;
    return 0;
}

bool isprime(unsigned number){
    if(number<=1) return false;
    for(unsigned i=2;i<=sqrt(number);++i){
        if(number%i==0){
            return false;
        }
    }
    return true;
}

vector<unsigned> generateNumbers(unsigned to, unsigned from)
{
	vector<unsigned> result;
	result.reserve(to - from + 1);//vector预存大小
	for (unsigned i = from; i <= to; ++i)
		result.push_back(i);
	return result;
}

vector<unsigned> filterPrimeNumbers(const vector<unsigned>& numbers)
{
	vector<unsigned> result;
	for (auto number : numbers)
	{
		if (isprime(number))
			result.push_back(number);
	}
	return result;
}

