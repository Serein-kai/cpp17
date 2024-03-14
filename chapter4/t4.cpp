/*4.本章前面提到寻找“年龄在 21~35 岁之间、拥有学士或硕士学历、未婚、说印地语或乌尔都语的女性”。
编写一个程序，提示用户输入自己的情况，然后输出她们是否满足这些具体的要求。
为此，需要定义一个整型变量 age,一个字符型变量 gender(用 m 代表男性，用 f 代表女性)，
一个枚举类型 AcademicDegree(可能的取值包括 none、associate、bachelor、professional、master、doctor)的变量 degree,
以及三个布尔变量 married、speaksHindi 和 speaksUrdu.模拟网上面试，要求申请人填写这些变量。输入无效值的人当然不满足条件，
应当尽早排除在外(即，在输入任何无效值以后立即排除他们)。


*/

#include <iostream>
using namespace std;

enum class AcademicDegree{
    none,associate,bachelor,professional,master,doctor
};

int main()
{
    int age{};
    char gender{};
    AcademicDegree degree{};
    char degreeChar{};
    bool married{};
    bool speaksHindi{};
    bool speaksUrdu{};

    cout<<"请输入你的年龄：";
    cin>>age;
    if(age<0||age>130){
        cout<<"你输入的信息不正确！"<<endl;
        return 1;
    }

    cout<<"请输入你的性别，m代表男性，f代表女性：";
    cin>>gender;
    if(gender!='m'&&gender!='f'){
        cout<<"你的信息不正确！"<<endl;
        return 1;
    }

    cout<<"请输入你的学位信息：\n\tn：没有学位\n\ta：associate's degree\n\tb: bachelor's dehree\n\tp: professional degree\n\tm: master's degree\n\td: doctorate\n";
    cin>>degreeChar;

    switch (degreeChar)
    {
    case 'n':degree=AcademicDegree::none;
        break;
    case 'a': degree = AcademicDegree::associate;
        break;
    case 'b': degree = AcademicDegree::bachelor;     
        break;	
    case 'p': degree = AcademicDegree::professional; 
        break;
    case 'm': degree = AcademicDegree::master;       
        break;
    case 'd': degree = AcademicDegree::doctor;       
        break;
    
    default:
        cout<<"你输入的信息不正确！"<<endl;
        return 1;
    }

    char y_n{};
    cout<<"你是否结婚（yorn）：";
    cin>>y_n;
    if(y_n=='y'){
        married=true;
    }else if (y_n=='n')
    {
        married=false;
        
    }else{
        cout<<"你输入的信息不正确！"<<endl;
        return 1;
    }

    cout<<"你是否会说印地语（yorn）";
    cin>>y_n;
    if(y_n=='y'){
        speaksHindi=true;
    }else if(y_n='n'){
        speaksHindi=false;
    }else{
        cout<<"你输入的信息不正确！"<<endl;
        return 1;
    }

    cout<<"你是否会说乌尔都语（yorn）";
    cin>>y_n;
    if(y_n=='y'){
        speaksUrdu=true;
    }else if(y_n='n'){
        speaksUrdu=false;
    }else{
        cout<<"你输入的信息不正确！"<<endl;
        return 1;
    }

    if((age>21&&age<35)&&gender=='f'&&(degree==AcademicDegree::bachelor||degree==AcademicDegree::master)
    &&!married&&(speaksHindi||speaksUrdu)){
        cout<<"你符合条件！"<<endl;
    }else{
        cout<<"你不符合条件！"<<endl;
    }
    

    return 0;
}
