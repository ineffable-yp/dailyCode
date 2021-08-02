#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;
int v = 1;
//在声明后的任意位置调用， 可以缩小锁的作用范围，提供更高的并发度
void critical_section_1(int change_v)
{
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    // 执行竞争操作
    v = change_v;
    std::cout << v << std::endl;
    // 将锁进行释放
    lock.unlock();
    // 在此期间，任何人都可以抢夺 v 的持有权
    // 开始另一组竞争操作，再次加锁
    lock.lock();
    v += 1;
    std::cout << v << std::endl;
}
// C++ 保证了所有栈对象在生命周期结束时会被销毁
// lock_guard不能显示调用lock和unlock
void critical_section(int change_v)
{
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);
    // 执行竞争操作
    v = change_v;
    // 离开此作用域后 mtx 会被释放
}

int main()
{
    std::thread t([]()
                  { std::cout << "hello world." << std::endl; });
    cout << "子线程: " << t.get_id() << endl;
    t.join();
    cout << "main线程:" << this_thread::get_id() << endl;
    std::thread t1(critical_section, 2), t2(critical_section, 3);
    t1.join();
    t2.join();

    std::cout << v << std::endl;
    // 将一个返回值为7的 lambda 表达式封装到 task 中
    // std::packaged_task 的模板参数为要封装函数的类型
    std::packaged_task<int(int)> task([](int a) -> int
                                      { return a; });
    // 获得 task 的期物
    std::future<int> result = task.get_future(); // 在一个线程中执行 task
    std::thread(std::move(task), 3).detach();
    //task();
    std::cout << "waiting...";
    result.wait(); // 在此设置屏障，阻塞到期物的完成
    // 输出执行结果
    std::cout << "done!" << std::endl
              << "future result is " << result.get() << std::endl;
    promise<int> p;
    auto task_g = [](future<int> a)
    { cout << a.get() << flush; };
    thread t3{task_g, p.get_future()};
    this_thread::sleep_for(chrono::seconds(5));
    p.set_value(20);
    t3.join();
    return 0;
}