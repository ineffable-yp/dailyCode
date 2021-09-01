#include <iostream>
#include <string>
using namespace std;
class B
{
    B()
    {
        cout << "B 构造\n";
    }
};
class A
{
public:
    A()
    {
        cout << "默认构造函数" << endl;
        name = "yinpan";
    }
    A(int x)
    {
        cout << "有参构造函数" << x << endl;
    }
    A(string str)
    {
        cout << "有参构造函数" << str << endl;
        name = str;
    }
    //拷贝构造函数必须以引用的方式传递参数。在值传递的方式传递给一个函数的时候，
    //会调用拷贝构造函数生成函数的实参。
    //如果拷贝构造函数的参数仍然是以值的方式，就会无限循环的调用下去，直到函数的栈溢出
    A(const A &a)
    {
        cout << "拷贝构造函数" << endl;
        name = a.name;
    }
    A(A &&a)
    {
        cout << "移动构造函数" << endl;
    }
    A &operator=(const A &a)
    {
        cout << "赋值函数";
        cout << name << endl;
        if (this != &a)
        {
            name = a.name;
        }
        return *this;
    }
    A &operator=(A &&a) noexcept
    {
        cout << "移动赋值函数";
        if (this != &a)
        {
            name = a.name;
        }
        cout << name << endl;
        return *this;
    }
    ~A()
    {
        cout << "析构函数" << endl;
    }

public:
    string name;
};

A getAobj(int str)
{
    A temp = A(str);
    return temp;
}
int main()
{
    A a;
    A a1("test");
    cout << "b对象之前\n";
    A b = a; //是否有新实例产生，有则调用拷贝构造函数
    A b1;    //只声明对象，在编译期系统为其分配内存
    b1 = a1;
    cout << "c对象之前\n";
    A c1;
    c1 = getAobj(2);
    return 0;
}