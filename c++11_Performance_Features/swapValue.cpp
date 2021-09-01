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
    return 0;
}