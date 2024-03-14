# configuration
launch.json
{
    //Use Intellisense to learn about possible attributes.
    //Hover to view descriptions of existing attributes.
    //For more information,visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version":"0.2.0",
    "configurations":[
        {
            "name":"myexe : makefile build and debug",    //name随便取，用来在定义了多个configuration的时候区分执行的是哪一套参数。
            "type":"cppdbg",        //这个一般就不要改了，这个我还不了解其他的参数配置
            "request":"launch",    //这个一般就不要改了，这个我还不了解其他的参数配置
            "program":"${workspaceRoot}/myexe",    //执行这个文件，相当于命令行中输入这行
            "args":["param1","param2","2>&1",">","out"],    //program的参数，相当于命令行中在program后输入用空格隔开的这些参数。我这里前两个是执行文件自带的参数设置，后三个是将标准输出和标准错误输入到文件out中。
            "stopAtEntry":false,    //大概是表示是否在main函数处停下，类似在main上打断点。
            "cwd":"${workspaceRoot}",    //表示在哪个目录下执行program，相当于命令行中输入cd 该行
            "environment":[],            //不知道干嘛的
            "externalConsole":true,    //如果使用控制台则需要打开这个。我这边加了这句后会有不知道在使用哪个控制台的问题，反正会很奇怪，就注释掉了。
            "MIMode":"gdb",            //使用哪个工具作为调试工具，只有两个选择gdb或lldb。lldb我不了解，和我一样不了解的人就写gdb吧。
            "miDebuggerPath":"/usr/bin/gdb",    //调试工具的路径
            "setupCommands":[    //gdb相关的一些设置命令，相当于在执行gdb后，对gdb下命令行的设置。gdb相关的初始化配置，要在~/.gdbinit文件中配置，或者在这配置，我另开一篇文章写，涉及下面enable-pretty-printing的，不一定开了就有用了，还涉及其他的问题，这里先放个TODO。
                {
                    "description":"Enable pretty-printing for gdb",    //给人看的描述
                    "text":"-enable-pretty-printing",        //gdb下执行的命令，启用整齐打印，就是让gdb打印的东西好看一点。
                    "ignoreFailures":true        //并不清楚这个实际用来干嘛
                },
                {
                    "description":"Let User defined signal 1 not appear",
                    "text":"handle SIGUSR1 nostop noprint",    //这个命令是我自己加的，因为我的程序会莫名奇妙出现调试时在非断点出停下的问题，用这个可以规避/忽视这个问题。
                    "ignoreFailures":true        //并不清楚这个实际用来干嘛
                }
            ],
            //"internalConsoleoptions":"openOnSessionstart",    //不知道干嘛的
            "preLaunchTask":"build"    //执行program前需要执行的task，这里需要和task.json中要执行的task的label一致
            //"preLaunchTask":""        //如果没有tasks.json，或者不需要执行前置task，则可以这样写，或不写这行。这种情况一般是你已经有了带调试信息的可执行文件，不要在再通过编译等操作得到了。
        }
    ]
}


tasks.json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ 生成活动文件",
            "command": "/usr/bin/g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}




# chapter7_t1
## 1. size_t
size_t 表示无符号整数，通常用于表示数组大小，内存分配大小等。例如vector 的size()函数返回的是size_t类型的值。
size_t i;

## 2. for(auto ch:sentence)
ch遍历了sentence中的每个元素。

## 3. getline(cin,text);
其中text是string类型的数据，需要在strin头文件。
getline(cin,text);//表示换行符是输入的结束。
getline(cin,text,'#')；//表示#是输入的结束。

## 4. string类型变量可以访问的函数
string phrase;
string name;
string word1,word2;
phrase.length();
phrase.substr(4,6);//从索引位4开始，提取6个字符的子字符串
phrase.swap(name);
phrase.compare("and");
word1.compare(2,word2.length(),word2)；//将word1中的子字符串与word2相比较。子字符串是从索引位置2开始，长度是word2的长度。
phrase.substr(7,4);

phrase.find(name);//返回name在phrase中的索引。
phrase.find(name,3);//从phrase下标为3的地方开始查找name，并返回索引

(index=text.find(word,index))!=std::string::npos;

phrase.find_first_of(name);//从phrase中找name第一个出现的下标
phrase.find_last_of();
phrase.find_first_not_of();//找不再字符集合中的字符。
phrase.rfind(word);//逆向搜索字符串

//插入字符串insert
phrase.insert(14,word);//把word字符串插入到phrase第14个位置之前
phrase.insert(14,word,8,5);//把word中第8个位置开始的包含5个字符的子字符串插入到phrase第14个位置之前
phrase.insert(14,word,5);//把word中的前5个单词插入到phrase的第14个索引字符前面
phrase.insert(14,7,'*');//把7个星号插入到phrase中的第14个索引位置的字符之前


//替换子字符串
phrase.replace(13,5,word);//在phrase中索引位置13开始的5个字符替换成word
phrase.replace(start,end-start,word,5,12);//在replace中start开始的end-start个字符替换成word中从5开始的12个字符
phrase.replace(start,end-start,word,12);//在replace中start开始的end-start个字符替换成word中前12个字符
phrase.replace(start,end-start,3,‘*’);//在replace中start开始的end-start个字符替换成3个*


//将数字转换为字符串
int num=123;
string str=to_string(num);

//将字符串转换为数组
//string文件头提供stoi(),stol()等
string s{"123"};
int i{stoi(s)};


//字符串流
//std::stringstream流，将字符收集到一个string对象中，使用方法和std::count一样
#include <sstream>
std::stringstream ss;
ss << std::setprecision(4) << std::setw(7) << std::right << values[i];
std::string s{ss.str()};
std::cout << s  << std::endl;

string my_string;
stringstream ss{my-string};
ss.str{my_string};//功能同上，将给定字符串的内容赋值给已有的字符串流。


//字符串排序
//注意，要对字符串排序，字符串中不能有空格
string str1 = "cba";
string str2 = "bac";
sort(str1.begin(), str1.end());
sort(str2.begin(), str2.end());



