#include <thread>
#include <atomic>
#include <iostream>
//原子操作:
//不会被线程调度打断的操作:操作一旦开始至运行结束，
//中间不会有任何的上下文切换
std::atomic<int> count = {0};

void test()
{
    std::thread t1([]()
                   { count.fetch_add(1); });
    std::thread t2([]()
                   {
                       count++;    // 等价于 fetch_add
                       count += 1; // 等价于 fetch_add
                   });
    t1.join();
    t2.join();
    std::cout << count << std::endl;
}
int main()
{
    int a = 0;
    int flag = 0;

    std::thread t1([&]()
                   {
                       while (flag != 1)
                           ;

                       int b = a;
                       std::cout << "b = " << b << std::endl;
                   });

    std::thread t2([&]()
                   {
                       a = 5;
                       flag = 1;
                   });

    t1.join();
    t2.join();
    return 0;
}