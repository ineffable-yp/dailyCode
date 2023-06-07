#include <iostream>
#include <thread>
#include <mutex>
#include <mingw.thread.h>
#include <atomic>
#include <cassert>

std::atomic<int> x(0), y(0), z(0);
std::atomic<bool> bContinue;
const int loop_num = 10;

struct Values
{
    int x, y, z;
};

Values v1[loop_num];
Values v2[loop_num];
Values v3[loop_num];
Values v4[loop_num];
Values v5[loop_num];

void increatement(std::atomic<int> *var_to_inc, Values *value)
{
    while (!bContinue)
    {
        std::this_thread::yield();
    }

    for (int i; i < loop_num; ++i)
    {
        value[i].x = x.load(std::memory_order_relaxed);
        value[i].y = y.load(std::memory_order_relaxed);
        value[i].z = z.load(std::memory_order_relaxed);
        var_to_inc->store(i + 1, std::memory_order_relaxed);
        std::this_thread::yield();
    }
    return;
}

void read_values(Values *value)
{
    while (!bContinue)
    {
        std::this_thread::yield();
    }
    for (int i; i < loop_num; ++i)
    {
        value[i].x = x.load(std::memory_order_relaxed);
        value[i].y = y.load(std::memory_order_relaxed);
        value[i].z = z.load(std::memory_order_relaxed);
        std::this_thread::yield();
    }
}

void print(Values *value)
{
    for (int i = 0; i < loop_num; ++i)
    {
        if (i)
        {
            std::cout << ", ";
        }
        std::cout << "(" << value[i].x << "," << value[i].y << "," << value[i].z << ")";
    }
    std::cout << std::endl;
}
int main(void)
{
    std::thread T1(increatement, &x, v1);
    std::thread T2(increatement, &y, v2);
    std::thread T3(increatement, &z, v3);
    std::thread T4(increatement, v4);
    std::thread T5(increatement, v5);
    bContinue = true;
    T5.join();
    T4.join();
    T3.join();
    T2.join();
    T1.join();
    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    return;
}