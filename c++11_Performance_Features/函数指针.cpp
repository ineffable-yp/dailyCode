#include <iostream>
using namespace std;

typedef void (*F)();

void f()
{
    cout << "normal function" << endl;
}

int main()
{
    F f1 = f;
    cout << "f  : " << (void *)f << endl;
    cout << "&f : " << reinterpret_cast<void *>(&f) << endl;
    cout << "*f1: " << reinterpret_cast<void *>(*f1) << endl;
    cout << "f1 : " << reinterpret_cast<void *>(f1) << endl;
    return 0;
}