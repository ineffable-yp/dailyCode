#include <iostream>
#include <cstddef>

//内存对齐:是按照成员的声明顺序，依次安排内存，其偏移量为成员大小的整数倍
//数据结构(尤其是栈)应该尽可能地在自然边界上对齐。原因在于，为了访问未对齐的内存，
//处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问
//#pragma pack(4)
struct Storage
{
    char a;
    int b;
    double c;
    long long d;
};

struct alignas(std::max_align_t) AlignasStorage
{
    char a;
    int b;
    double c;
    long long d;
};

int main()
{
    //sizeof返回一个对象或者类型所占的内存字节数
    std::cout << sizeof(Storage) << std::endl;
    //类型必须与多少字节对齐，即指定类型的对齐方式返回为类型的值
    std::cout << alignof(Storage) << std::endl;
    std::cout << alignof(AlignasStorage) << std::endl;
    return 0;
}