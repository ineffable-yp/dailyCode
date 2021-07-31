#include <vector>
#include <iostream>
using namespace std;
// c++ 11/14/17链接
//https://changkun.de/modern-cpp/zh-cn/04-containers/index.html
class testDemo
{
public:
    testDemo(int num) : num(num)
    {
        std::cout << "调用构造函数" << endl;
    }
    testDemo(const testDemo &other) : num(other.num)
    {
        std::cout << "调用拷贝构造函数" << endl;
    }
    testDemo(testDemo &&other) : num(other.num)
    {
        std::cout << "调用移动构造函数" << endl;
    }

private:
    int num;
};

int main()
{
    cout << "emplace_back:" << endl;
    std::vector<testDemo> demo1;
    demo1.emplace_back(2);

    cout << "push_back:" << endl;
    std::vector<testDemo> demo2;
    demo2.push_back(2);
}