#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> s;
    cout << s.size() << "--" << s.capacity() << endl;
    s.push_back(2);
    cout << s.size() << "--" << s.capacity() << endl;

    char *name = (char *)get_name(); //不安全 破坏设计函数的初衷
    name[0] = 'J';                   //在rust中unsafe关键字 部分安全（暂时）
    printf("name: %s\n", name);
    free(name);
    return 0;
}
