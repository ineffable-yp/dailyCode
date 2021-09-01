#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "A Default constructor" << endl;
    }
    A(int a)
    {
        mA_a = a;
        cout << "A constructor" << endl;
    }
    A(const A &)
    {
        cout << "A copy constructor" << endl;
    }
    A &operator=(const A &a)
    {
        cout << "A assign operator" << endl;
        if (this != &a)
        {
            this->mA_a = a.mA_a;
        }
        return *this;
    }
    ~A()
    {
        cout << "A deconstructor" << endl;
    }

private:
    int mA_a;
};
class B
{
public:
    B()
    {
        cout << "B Default Constructor" << endl;
    }
    // B(A &a)
    // {
    //     cout << "come into B" << endl;
    //     _a = a; // A的赋值运算
    //     cout << "B Constructor" << endl;
    // }
    B(A &a) : _a(a) //列表执行优于函数体
    {
        cout << "come into B" << endl;
        cout << "B Constructor" << endl;
    }

private:
    A _a;
};
int main()
{
    A a;
    B b(a); //编译器会隐式对未初始化的默认 调用A的默认构造 - B的拷贝构造
    //析构a
    return 0;
}
