#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>

using namespace std;

void pass_by_value(int *p)
{
    p = new int;
}
void pass_by_ref(int *&p)
{
    p = new int;
}
int main()
{
    auto x = 1, y = 3;
    decltype(x + y) z;
    if (is_same<decltype(z), int>::value)
        cout << "int ...\n";
    int *p1, *p2;
    p1 = nullptr;
    p2 = nullptr;

    pass_by_value(p1);
    pass_by_ref(p2);
    if (p1 == nullptr)
        cout << "value:Pointer variable can not be updated... \n";
    if (p2 != nullptr)
        cout << "ref:Pointer variable can be updated... \n";
    return 0;
}