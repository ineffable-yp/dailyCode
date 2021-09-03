#include <iostream>

using namespace std;

int main()
{
    //附加const *（指向常量的指针） 与 * const（常量指针）
    int a = 3, b3 = 5;
    //
    const int *p = &a;
    //*p = 4; //error 指向地址的内容不可修改
    p = &b3;            //ok 指向地址可以修改
    int *const p1 = &a; //const修饰p1
    //p1 = &b3; // error 指向地址不可修改
    *p1 = 4; //ok 指向地址内的内容可修改

    const int *&rp = p; //指向常量的指针的引用
    rp = &b3;

    int *const &rp1 = p1; //常量指针的引用
    *rp1 = 10;
    return 0;
}