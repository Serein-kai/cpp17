# 函数模板
## 1、函数模板是参数化函数定义。函数模板的参数通常是数据类型，也可以是维度。
template <typename T> 
const T larger(const T& a,const T& b){
    return a>b?a:b;
}

## 2、模板实参推断
直接larger(1.5,2.5)

## 3、显示指定模板实参
larger<double>(small_int,199.6)，double类型的T，第一个参数隐式转换。

## 4、函数模板的特例：在原始模板的声明或定义之后，定义特定的模板
原始模板：
template <typename T> 
const T larger(const T& a,const T& b){
    return a>b?a:b;
}

特定的模板
template <> 
int* larger(int* a,int* b){
    return *a>*b?a:b;
}

## 5、函数模板和重载
定义一个模板的重载函数，使用函数定义和函数声明。
int* larger(int*a,int*b);

可以用另一个模板重载已有的模板。
template <typename T> 
T larger(const T data[] a,const T  count){
    T result {data[0]};
    for(size_t i {i};i< count;++i)
        if(data[i]>result) result=data[i];
    return result;
}

另外一个重载：
template <typename T> 
T larger(const std::vector<T>& data){
    T result {data[0]};
    for(auto& value:data)
        if(value>result) result=value;
    return result;
}

可以用指针类型定义的另一个模板来重载原始模板
template <typename T> 
T* larger(T* a,iT* b){
    return *a>*b?a:b;
}


## 6、带有多个参数的函数模板
template <typename TReturn,typename Targ1,typename TArg2>
TRetrun larger(TArg1 a,TArg2 b){
    return a>b?a:b;
}

larger<size_t>(1.5,2)。返回值类型必须指定，参数类型可以不用指定。

## 7、模板的返回类型推断
template <typename Targ1,typename TArg2>
auto larger(TArg1 a,TArg2 b){
    return a>b?a:b;
}

## 8、拖尾decltype，deltype(auto)
template <typename T1,typename T2>
auto larger(T1 a,T2 b)->decltype(a>b?a:b){
    return a>b?a:b;
}

template <typename T1,typename T2>
decltype(auto) larger(T1 a,T2 b){
    return a>b?a:b;
}

## 9、非类型的模板参数
template <int lower,int upper,typename T>
bool is_in_range(const T& value){
    return (value<=upper>&&(value>=lower));
}

cout<<is_in_range<0,500>(value)；

使用固定大小数组实参的函数模板
template <typename T,size_t N>
T average(const T (&array)[N]){

}
编译器可以自动推断。



