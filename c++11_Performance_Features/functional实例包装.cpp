#include <iostream>
#include <functional>

using namespace std;
//定义函数指针
typedef int (*Fun_ptr)(int);
//function包装
function<int(int)> callback;

template <typename T>
T func_2(T a)
{
    return a + 2;
}

struct add
{
    int operator()(int x)
    {
        return x + 9;
    }
};

template <typename T>
struct sub
{
    T operator()(T a)
    {
        return a - 10;
    }
};

template <typename T>
struct Foo
{
    //静态函数作用域局限于定义函数的文件内
    //普通函数默认是extern的
    static T foo(T a)
    {
        return a * 4;
    }
};

struct Foo3
{
    int func_4(int x)
    {
        return x * x;
    }
};

int func_1(int a)
{
    return a;
}

int main()
{
    Fun_ptr fptr = func_1;
    callback = fptr;        //包装函数指针
    callback = func_1;      //包装函数
    callback = func_2<int>; //包装模板函数
    callback = add();       //包装对象函数

    auto func_3 = [](int a) -> int
    { return a * 2; };

    callback = func_3;        //包装lamda表达式
    callback = sub<int>();    //包装模板对象函数
    callback = Foo<int>::foo; //包装模块对象静态函数

    Foo3 foo3;
    /*
    * std::bind的思想其实是一种延迟计算的思想，将可调用对象保存起来，然后在需要的时候再调用。
    * 而且这种绑定是非常灵活的，不论是普通函数还是函数对象还是成员函数都可以绑定，
    * 而且其参数可以支持占位符。
    * std::placeholders::_1是一个占位符，且绑定第一个参数，
    * 若可调用实体有2个形参，那么绑定第二个参数的占位符是std::placeholders::_2。
    */
    callback = bind(&Foo3::func_4, foo3, placeholders::_1); //包装类成员函数

    function<int(int)> callback2 = callback;         //拷贝赋值运算符
    function<int(int)> &&callback3 = move(callback); //移动赋值运算符
    cout << callback3(10) << endl;                   //返回的是右值
    cout << callback(10) << endl;

    function<int(int)> callback4(callback); //拷贝
    cout << callback4(20) << endl;
    return 0;
}
