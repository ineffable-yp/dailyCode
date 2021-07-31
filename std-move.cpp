#include <iostream>
#include <utility>
#include <string>
#include <vector>

class A
{
public:
    int *pointer;
    A() : pointer(new int(1))
    {
        std::cout << "construct " << pointer << std::endl;
    }
    A(A &a) : pointer(new int(*a.pointer))
    {
        std::cout << "copy " << pointer << std::endl;
    } //无意义的对象拷贝
    A(A &&a) : pointer(a.pointer)
    {
        a.pointer = nullptr;
        std::cout << "move " << pointer << std::endl;
    }
    ~A()
    {
        std::cout << "deconstruct " << pointer << std::endl;
        delete pointer;
    }
};
// 防止编译器优化
A return_rvalue(bool test)
{
    A a, b;
    if (test)
        return a; // 等价于 static_cast<A&&>(a);
    else
        return b; // 等价于 static_cast<A&&>(b);
}
int main()
{
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl; //地址
    std::cout << *obj.pointer << std::endl;

    std::string hestr = "hello,yinpan";
    std::vector<std::string> v;
    // 将使用 push_back(const T&), 即产生拷贝行为
    v.push_back(hestr);
    // 将输出 "str: Hello world."
    std::cout << "str: " << hestr << std::endl;

    // 将使用 push_back(const T&&), 不会出现拷贝行为
    // 而整个字符串会被移动到 vector 中，所以有时候 std::move 会用来减少拷贝出现的开销
    // 这步操作后, str 中的值会变为空
    v.push_back(std::move(hestr));
    // 将输出 "str: "
    std::cout << "str: " << hestr << std::endl;
    return 0;
}