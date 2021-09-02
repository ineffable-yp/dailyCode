#include <iostream>
#include <cmath>
using namespace std;
//隐式转换是安全的，显示转换是不安全的
/*
    static_cast:基本类型转换，类的上行转换（安全）类的下行转换（不安全，无类型检查）
    dynamic_cast: 类的上行转换（安全），下行转换（安全）需要运行时信息，信息位于虚函数表。
    const_cast:改变类型的常量属性；指针，引用，对象
    reinterpret_cast:非关联类型的转换，操作结果一个指针到其他指针的二进制拷贝，无类型检查
*/
class Base
{
    virtual void print() {}
};
class Derive : public Base
{
};

int main()
{
    /*static_cast例子*/
    //static_cast不能转换const修饰属性 volitie修饰属性
    // const int a1 = 10;
    // int *h = static_cast<int>(&a1);
    char a = 'a';
    int b = static_cast<int>(a);
    const int f = static_cast<const int>(b);
    double *c = new double;
    void *d = static_cast<void *>(c);
    //上下行转换
    Base *a1 = new Base;
    Derive *b1 = nullptr;
    Base *a2 = nullptr;
    b1 = static_cast<Derive *>(a1); //下行转换,不安全:b1访问子类的成员时
    a2 = static_cast<Base *>(b1);   //上行转换
    /*const_cast*/
    const int g1 = 20;
    int *h1 = const_cast<int *>(&g1);
    const int g2 = 20;
    int &h2 = const_cast<int &>(g2);
    const char *g3 = "hello";
    char *h3 = const_cast<char *>(g3);
    /*dynamic_cast 只用于对象指针和引用*/
    Base *b11 = new Derive;
    Base *b22 = new Base;
    Derive *d11 = dynamic_cast<Derive *>(b11); // 合理
    Derive *d22 = dynamic_cast<Derive *>(b22); // 转换失败

    /*reinpreter_cast 非相关的类型之间转换,从一个指针到别的指针的值的二进制拷贝*/
    int *p = &b;
    unsigned int val = reinterpret_cast<unsigned int>(p);
    //辅助哈希函数MSDN
    /*
    // Returns a hash code based on an address
    unsigned short Hash(void *p)
    {
        unsigned int val = reinterpret_cast<unsigned int>(p);
        return (unsigned short)(val ^ (val >> 16));
    }
    using namespace std;
    int main()
    {
        int a[20];
        for (int i = 0; i < 20; i++)
            cout << Hash(a + i) << endl;
    }
    */
    return 0;
}
