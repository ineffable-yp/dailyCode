#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Foo
{
public:
    Foo(std::string str) : name(str)
    {
        std::cout << "constructor" << std::endl;
    }
    Foo(const Foo &f) : name(f.name)
    {
        std::cout << "copy constructor" << std::endl;
    }
    Foo(Foo &&f) : name(std::move(f.name))
    {
        std::cout << "move constructor" << std::endl;
    }

private:
    std::string name;
};

int main()
{
    std::vector<Foo> v;
    int count = 10000000;
    v.reserve(count); //预分配十万大小，排除掉分配内存的时间
    {
        Foo temp("ceshi");
        v.push_back(temp); // push_back(const T&)，参数是左值引用(可以通过地址访问)
        //打印结果：
        //constructor
        //copy constructor
    }

    v.clear();
    {
        Foo temp("ceshi");
        v.push_back(std::move(temp)); // push_back(T &&), 参数是右值引用
        //打印结果：
        //constructor
        //move constructor
    }

    v.clear();
    {
        v.push_back(Foo("ceshi")); // push_back(T &&), 参数是右值引用
        //打印结果：
        //constructor
        //move constructor
    }

    v.clear();
    {
        std::string temp = "ceshi";
        v.push_back(temp); // push_back(T &&), 参数是右值引用
        //打印结果：
        //constructor
        //move constructor
    }

    v.clear();
    {
        std::string temp = "ceshi";
        v.emplace_back("ceshi"); // 只有一次构造函数，不调用拷贝构造函数，速度最快
        //打印结果：
        //constructor
    }
}
