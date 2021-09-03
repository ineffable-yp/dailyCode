#include <iostream>

using namespace std;
class Base
{
public:
    void setM() const;
    int m;
};

void Base::setM() const
{
    cout << m << endl;
    //m=3; const限制不允许修改成员变量的值
    //保证不会修改函数内部状态
}
int main()
{
    int a = 2, b = 3;
    int *arr[] = {&a, &b};
    cout << "a: " << &a << endl;
    int **ptr = arr; //指向指针数组的指针
    cout << "arr: " << arr << endl;
    cout << "ptr: " << arr << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "*(ptr+i): " << *(ptr + i) << endl;
    }
}