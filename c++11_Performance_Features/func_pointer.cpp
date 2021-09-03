#include <iostream>

using namespace std;

int (*func_pointer)(int &);

int addOne(int &x)
{
    cout << __FUNCTION__ << " : ";
    x += 1;
    return x;
}
int addTwo(int &x)
{
    cout << __FUNCTION__ << " : ";
    x += 2;
    return x;
}

int main()
{
    int x1 = 3, x2 = 3;
    int ret = 0;

    cout << "addTwo 地址: ";
    cout << reinterpret_cast<void *>(addTwo) << endl;
    func_pointer = addTwo;
    ret = func_pointer(x1); //期待值 5
    cout << reinterpret_cast<void *>(func_pointer) << endl;
    cout << ret << endl;

    cout << "addOne 地址: ";
    cout << reinterpret_cast<void *>(addOne) << endl;
    func_pointer = addOne;
    ret = (*func_pointer)(x2); //期待值 4 ===func_pointer(x2)
    cout << reinterpret_cast<void *>(func_pointer) << endl;
    cout << ret << endl;

    cout << "main : ";
    cout << reinterpret_cast<void *>(main) << endl;
    return 0;
}
