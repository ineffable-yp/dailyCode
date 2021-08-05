#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
/*一是wait系列方法存在虚假唤醒 ;
二对于从wait中被notify的进程来说，它在被notify之后还需要重新检查是否符合执行条件，
如果不符合，就必须再次被wait，如果符合才能往下执行.所以：wait方法应该使用循环模式
来调用。按照上面的生产者和消费者问题来说：错误情况一：如果有两个生产者A和B，一个消
费者C。当存储空间满了之后，生产者A和B都被wait，进入等待唤醒队列.当消费者C取走了一
个数据后，如果调用了notifyAll（），注意，此处是调用notifyAll（），则生产者线程A和
B都将被唤醒，如果此时A和B中的wait不在while循环中而是在if中，则A和B就不会再次判断是
否符合执行条件，都将直接执行wait（）之后的程序，那么如果A放入了一个数据至存储空间，
则此时存储空间已经满了；但是B还是会继续往存储空间里放数据，错误便产生了。错误情况二：
如果有两个生产者A和B，一个消费者C。当存储空间满了之后，生产者A和B都被wait，进入等待
唤醒队列。当消费者C取走了一个数据后，如果调用了notify（），则A和B中的一个将被唤醒，
假设A被唤醒，则A向存储空间放入了一个数据，至此空间就满了。A执行了notify（）之后，如
果唤醒了B，那么B不会再次判断是否符合执行条件，将直接执行wait（）之后的程序，这样就导
致向已经满了数据存储区中再次放入数据。错误产生*/
int main()
{
    std::queue<int> produced_nums;
    std::mutex mtx;
    std::condition_variable cv;
    bool notified = false; // 通知信号

    // 生产者
    auto producer = [&]()
    {
        for (int i = 0;; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(900));
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << "producing " << i << std::endl;
            produced_nums.push(i);
            notified = true;
            cv.notify_all(); // 此处也可以使用 notify_one
        }
    };
    // 消费者
    auto consumer = [&]()
    {
        while (true)
        {
            std::unique_lock<std::mutex> lock(mtx);
            while (!notified)
            { // 避免虚假唤醒
                cv.wait(lock);
            }
            // 短暂取消锁，使得生产者有机会在消费者消费空前继续生产
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 消费者慢于生产者
            lock.lock();
            while (!produced_nums.empty())
            {
                std::cout << "consuming " << produced_nums.front() << std::endl;
                produced_nums.pop();
            }
            notified = false;
        }
    };

    // 分别在不同的线程中运行
    std::thread p(producer);
    std::thread cs[2];
    for (int i = 0; i < 2; ++i)
    {
        cs[i] = std::thread(consumer);
    }
    p.join();
    for (int i = 0; i < 2; ++i)
    {
        cs[i].join();
    }
    return 0;
}