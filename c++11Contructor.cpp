#include <iostream>
#include <type_traits>
#include <functional>
using namespace std;

class Base
{
public:
    int value1;
    int value2;
    Base()
    {
        value1 = 1;
    }
    Base(int value) : Base()
    { // 委托 Base() 构造函数
        value2 = value;
    }
};
class Subclass : public Base
{
public:
    using Base::Base; // 继承构造
};

class Magic
{
public:
    Magic() = default;
    Magic &operator=(const Magic &) = delete;
    Magic(int magic_number);
};

enum class num : unsigned int
{
    value1,
    value2 = 100
};

int foo(int para)
{
    return para;
}
int main()
{
    Subclass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;

    int value = 1;
    auto copy_value = [=]
    {
        return value;
    };

    value = 100;
    cout << copy_value() << endl;

    //函数对象包装器
    // std::function 包装了一个返回值为 int, 参数为 int 的函数
    std::function<int(int)> func = foo;

    int important = 10;
    std::function<int(int)> func2 = [&](int value) -> int
    {
        return 1 + value + important;
    };
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
}

// struct Base
// {
//     virtual void foo() final;
// };
// struct SubClass1 final : Base
// {
// }; // 合法

// struct SubClass2 : SubClass1
// {
// }; // 非法, SubClass1 已 final

// struct SubClass3 : Base
// {
//     void foo(); // 非法, foo 已 final
// };