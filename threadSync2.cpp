#include <iostream>
#include <stdio.h>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

condition_variable cond;
mutex _mutex;
int a = 0;

void first()
{
    while (true)
    {
        unique_lock<mutex> lck(_mutex);
        while (a % 3 != 0)
            cond.wait(lck);
        a++;
        printf("%d\n", a % 3);
        cond.notify_all();
        lck.unlock();
    }
}
void second()
{
    while (true)
    {
        unique_lock<mutex> lck(_mutex);
        while (a % 3 != 1)
            cond.wait(lck);
        a++;
        printf("%d\n", a % 3);
        cond.notify_all();
    }
}
void third()
{
    while (a < 100)
    {
        unique_lock<mutex> lck(_mutex);
        while (a % 3 != 2)
            cond.wait(lck);
        a++;
        printf("%d\n", a % 3);
        cond.notify_all();
    }
}

int main()
{
    thread t1(first);
    thread t2(second);
    thread t3(third);
    getchar();
    return 0;
}
