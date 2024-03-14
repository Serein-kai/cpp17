/*5.编写一个程序，定义 Color 类型的枚举，
其枚举成员是 Red、Green、Yellow、Puple、 Blue、 Black 和 White。
把枚举成员的类型定义为不带符号的整数，
将每个枚举成员的整数值指定为所表示颜色的 RGB 值
(在网上可以轻松找到任何颜色的十六进制 RGB 编码)。
创建 Color 类型的变量，用枚举成员 Yellow、Puple 和 Green 来初始化。
访问枚举成员的值，提取 RGB 成分，并输出为单独的值。

*/



#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const unsigned R{0x00FF0000};
    const unsigned G(0x0000FF00);
    const unsigned B{0x000000FF};

    enum class Color:unsigned{   //后面跟:类型
    Red=R,         //red=0x00ff0000
    Green=G,        //green=0x0000ff00
    Yellow=R|G,     //yellow=0x00ffff00
    Puple=R|B,          //puple=0x00ff00ff
    Blue=B,       //blue=0x000000ff  
    Black=0,          //black=0x00000000
    White=R|G|B           //white=0x00ffffff
};
    const Color color1{Color::Yellow};
    const Color color2{Color::Puple};
    const Color color3{Color::Green};


    auto color {static_cast<unsigned>(color1)};                         //类型转换，color1是const Color类型，但是在和R运算的时候，R是const unsigned类型，要转换一下 
    cout<<left << std::setw(20) << "yellow的RGB成分:"
    << "  R:" <<left<< std::setw(3) << ((color & R) >> 16)
    << "  G:" << std::setw(3) << ((color & G) >> 8)
    << "  B:" << std::setw(3) << (color & B) << endl;

    color=static_cast<unsigned>(color2);
    cout <<left<< std::setw(20) << " Puple的RGB成分:"
    << "  R:" << std::setw(3) << ((color & R) >> 16)
    << "  G:" << std::setw(3) << ((color & G) >> 8)
    << "  B:" << std::setw(3) << (color & B) << endl;

    color=static_cast<unsigned>(color3);
    cout <<left<< std::setw(20) << " Green的RGB成分:"
    << "  R:" << std::setw(3) << ((color & R) >> 16)
    << "  G:" << std::setw(3) << ((color & G) >> 8)
    << "  B:" << std::setw(3) << (color & B) << endl;

    return 0;

}