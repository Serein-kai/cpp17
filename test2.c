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





settings.json
{
    "files.associations": {
        "array": "cpp",
        "atomic": "cpp",
        "bit": "cpp",
        "*.tcc": "cpp",
        "cctype": "cpp",
        "clocale": "cpp",
        "cmath": "cpp",
        "compare": "cpp",
        "concepts": "cpp",
        "cstdarg": "cpp",
        "cstddef": "cpp",
        "cstdint": "cpp",
        "cstdio": "cpp",
        "cstdlib": "cpp",
        "cwchar": "cpp",
        "cwctype": "cpp",
        "deque": "cpp",
        "string": "cpp",
        "unordered_map": "cpp",
        "vector": "cpp",
        "exception": "cpp",
        "algorithm": "cpp",
        "functional": "cpp",
        "iterator": "cpp",
        "memory": "cpp",
        "memory_resource": "cpp",
        "numeric": "cpp",
        "random": "cpp",
        "string_view": "cpp",
        "system_error": "cpp",
        "tuple": "cpp",
        "type_traits": "cpp",
        "utility": "cpp",
        "initializer_list": "cpp",
        "iosfwd": "cpp",
        "iostream": "cpp",
        "istream": "cpp",
        "limits": "cpp",
        "new": "cpp",
        "numbers": "cpp",
        "ostream": "cpp",
        "stdexcept": "cpp",
        "streambuf": "cpp",
        "typeinfo": "cpp",
        "iomanip": "cpp"
    }
}

c_cpp_properties.json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}



