#include <iostream>

using namespace std;

class B
{
public:
    virtual void test1()
    {
        cout << "hello test1" << endl;
    }
    virtual void test2()
    {
        cout << "hello test2" << endl;
    }
};
class C : public B
{
public:
    virtual void test1()
    {
        cout << "hello test C1\n";
    }
    virtual void test3()
    {
        cout << "hello test3\n";
    }
};

int main()
{
    typedef void (*Func)(); //函数指针

    B *b = new B;
    cout << "object b address: " << b << endl;
    int vtable = *(reinterpret_cast<int *>(b)); //虚函数表首地址==vptr解引用
    for (int i = 0; i < 2; i++)
    {
        int address = *(reinterpret_cast<int *>(vtable + 8 * i)); //虚函数入口地址
        cout << "virtual function " << i << ": " << address << endl;
        Func f = reinterpret_cast<Func>(address);
        f();
    }

    cout << "\n";

    C *c = new C;
    cout << "object c address: " << c << endl;
    int vtable2 = *(reinterpret_cast<int *>(c)); //虚函数表首地址==vptr解引用
    for (int i = 0; i < 3; i++)
    {
        int address = *(reinterpret_cast<int *>(vtable2 + 8 * i)); //虚函数入口地址
        cout << "virtual function " << i << ": " << address << endl;
        Func f = reinterpret_cast<Func>(address);
        f();
    }
    delete c;
    delete b;
    return 0;
}
