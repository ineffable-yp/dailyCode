#include <iostream>

using namespace std;

class A
{
public:
    A(int size) : m_size(size)
    {
        data = new int[m_size];
    }
    A() {}
    A(const A &a)
    {
        //浅拷贝，只是数据的简单赋值
        this->m_size = a.m_size;
        //this->data = a.data;
        //深拷贝，分配一块内存
        this->data = new int[m_size];
        cout << "copy construct\n";
    }
    //移动语义 转移所有权
    A(A &&a)
    {
        this->data = a.data;
        a.data = nullptr;
        cout << "move construct" << endl;
    }
    ~A()
    { //会引起double free问题
        if (data != nullptr)
            delete[] data;
    }
    int *data;
    int m_size;
};
int main()
{
    A a(10);
    A b = a;
    cout << "move前: " << a.data << endl;
    cout << "拷贝后: " << b.data << endl;

    /**移动语义仅针对实现了移动构造函数的类对象**/
    A c = std::move(a);
    cout << "move后: " << a.data << endl;
    cout << "c: " << c.data << endl;
    return 0;
}