#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;
template <typename T>
inline T const &Max(T const &a, T const &b) //函数体内值不被修改，返回值不能为左值
{
    return a < b ? b : a;
}

int number = 0;
const char *get_name()
{
    number += 1;
    char *name = (char *)malloc(10);
    snprintf(name, 10, "jam%i", number);
    return name;
}

int main()
{
    int sum = 0;
    for (unsigned char i = 0; i < 1000; i++)
    {
        cout << (int)i << endl;
        sum += i;
    }
    cout << sum << endl;
    //vector底层扩容
    vector<int> s;
    cout << s.size() << "--" << s.capacity() << endl;
    s.push_back(2);
    s.resize(0);
    cout << s.size() << "--" << s.capacity() << endl;
    //动态内存1
    int *ipt = new int;
    cout << "sizeof(int*):" << sizeof(ipt) << endl;
    cout << "0取反: " << (unsigned)~0 << endl;
    *ipt = 13;
    delete ipt;
    //动态内存2*3列
    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
        arr[i] = new int[3];

    for (int i = 0; i < 2; i++)
        delete[] arr[i];
    delete[] arr;
    cout << Max(4, 5) << endl;
    char *name = (char *)get_name(); //不安全 破坏设计函数的初衷
    name[0] = 'J';                   //在rust中unsafe关键字 部分安全（暂时）
    printf("name: %s\n", name);
    free(name);

    return 0;
}
