#include <iostream>
using namespace std;

void p2(int);
void p2(void *);
int main()
{
    //p2(NULL); //gcc 编译报错
    p2(nullptr);
}
void p2(int a)
{
    cout << "p2 int " << endl;
}
void p2(void *a)
{
    cout << "p2 void*" << endl;
}