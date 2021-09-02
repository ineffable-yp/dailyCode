#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap1(int *&a, int *&b)
{
    int *temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 3, b = 5;
    int *p1 = &a, *p2 = &b;
    swap1(p1, p2);
    cout << *p1 << "  " << *p2 << endl;

    int &r = a;
    int *p = &a;
    cout << sizeof(r) << endl; //变量大小
    cout << sizeof(p) << endl; //地址大小
    cout << &r << endl;
    cout << &a << endl;
    cout << &p << endl;
    return 0;
}
