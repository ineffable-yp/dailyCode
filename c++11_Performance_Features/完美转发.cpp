#include <iostream>
#include <string>
using namespace std;

class A
{
public:
    int value;
    explicit A(int value) : value(value)
    {
        std::cout << "construct" << std::endl;
    }
    ~A()
    {
        std::cout << "deconstruct" << std::endl;
    }
};

void test(A &&a, double b)
{
    std::cout << a.value << " " << b << std::endl;
}

//右值保持
template <class... Args>
void test_forward(Args &...args)
{
    test(std::forward<Args>(args)...);
}

//普通完美转发测试
template <typename T>
void test(T &&x)
{
    cout << "右值: " << x << endl;
}
template <typename T>
void test(T &x)
{
    cout << "左值: " << x << endl;
}
template <typename T>
void testforward(T &&x)
{
    test(x);
    test(move(x));
    test(forward<T>(x));
}

int main()
{
    A a(1);
    float b = 2.1;
    test_forward(a, b);
    a.value = 2;
    test_forward(a, b);

    string A("test");
    string &&rval = move(A);
    cout << A << endl;

    string B(forward<string>(rval));
    cout << "forward后: " << A << endl;
    cout << endl;

    testforward(1);
    cout << "========" << endl;
    int x = 1;
    testforward(x);
    return 0;
}