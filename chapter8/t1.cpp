/*
1.编写一个函数 validate input0，它接收两个整数实参，表示所输入整数的上下限。它接收的第三个实参是描述输入的字符串，用于提示用户输入。
该函数会提示所输入的值应在前两个实参指定的范围之内，并包含标识输入值类型的字符串。该函数应检查输入并一直提示用户输入值，直到输入的值有效为止。
在程序中使用 validate input0函数，获取用户的生日并以下面的格式输出:
November 21，2012
这个程序应使各个函数 month0、year0和 day0管理对应数字的输入，不要忘了闰年。2017 年 2 月 29 日是不允许输入的。
*/

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

//如果能被4整除，但是不能被100整除，是闰年。如果能过被400整除，是闰年。
bool isleapyear(int year){
    return (year%4==0&&year%100!=0)||(year%400==0);
}

int validate_input(int lower,int upper,string_view description){
    int data{};
    cout<<"请在"<<lower<<"到"<<upper<<"范围内，输入"<<description<<":";
    cin>>data;
    while (data<lower||data>upper)
    {
        cout<<"您输入的数据不合法，请重新输入"<<description<<":"<<endl;
        cin>>data;
    }
    return data;
}

int year(){
    const int low_year{1924};
    const int up_year{2024};
    return validate_input(low_year,up_year,"年");
}

int month(){
    const int low_month{1};
    const int up_month{12};
    return validate_input(low_month,up_month,"月");
}

//因为日的上下限要根据月，而月的大小又跟是否闰年有关
int date(int month_data,int year_data){
    const int low_date{1};
    const int feb{2};
    static const int up_date[] {31,28,31,30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(month_data==feb && isleapyear(year_data)){
        return validate_input(low_date,up_date[month_data-1]+1,"日");
    }else{
        return validate_input(low_date,up_date[month_data-1],"日");
    }
}


int main()
{
    cout<<"请输入你的生日"<<endl;
    int date_year {year()};
    int date_month {month()};
    int date_day {date(date_month,date_year)};
    string months[] {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "October", "November", "December"};
    cout<<endl<<"你出生的日期为："<<months[date_month-1]<<" "<<date_day<<","<<date_year<<endl;
    return 0;
}