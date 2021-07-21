#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>
#include <string>

using namespace std;

int a = 0;

//自旋锁
atomic_flag flag;
void foo()
{
    for (int i = 0; i < 10000000; ++i)
    {
        while (flag.test_and_set())
        {
        } //加锁
        a += 1;
        flag.clear(); //解锁
    }
}
//互斥锁
mutex _mutex;
void foo_mutex()
{
    for (int i = 0; i < 10000000; ++i)
    {
        _mutex.lock();
        a += 1;
        _mutex.unlock();
    }
}

int main()
{
    flag.clear(); //初始状态

    clock_t start, end;
    start = clock();
    thread t1(foo);
    thread t2(foo);
    t1.join();
    t2.join();
    end = clock();
    cout << a << endl;
    cout << end - start << endl;

    string a = "hello,this is COW test";
    string b = a;

    //动态分配小内存的开销 相对于 频繁开辟大内存的开销略小
    if (b.data() == a.data())
        cout << "COW技术1\n";
    b.append("A");
    if (b.data() == a.data())
        cout << "COW技术2\n";
    return 0;
}
