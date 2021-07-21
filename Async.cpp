#include <future>
#include <string>
#include <thread>
#include <iostream>
#include <cassert>
#include <exception> // std::exception, std::current_exception

void get_int(std::promise<int> &prom)
{
    int x;
    std::cout << "Please, enter an integer value: ";
    std::cin.exceptions(std::ios::failbit); // throw on failbit
    try
    {
        std::cin >> x; // sets failbit if input is not int
        prom.set_value(x);
    }
    catch (std::exception &)
    {
        prom.set_exception(std::current_exception());
    }
}

void print_int(std::future<int> &fut)
{
    try
    {
        int x = fut.get();
        std::cout << "value: " << x << '\n';
    }
    catch (std::exception &e)
    {
        std::cout << "[exception caught: " << e.what() << "]\n";
    }
}

void print(std::promise<std::string> &p, std::string name)
{
    p.set_value("There is the result whitch you want." + name);
}

bool isPrime(int x)
{
    assert(x > 0);
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    std::promise<std::string> promise;
    std::string name = "yinpan";
    std::future<std::string> result = promise.get_future();
    std::future<bool> fu = std::async(isPrime, 444444443);

    std::chrono::milliseconds span(100);
    //每隔0.1s检测一次状态
    while (fu.wait_for(span) == std::future_status::timeout)
    {
        std::cout << ".";
    }
    std::cout << "\n444444443 " << (fu.get() ? "is" : "is not") << " a prime" << std::endl;
    std::thread t(print, std::ref(promise), std::ref(name));
    std::cout << result.get() << std::endl;
    t.join();

    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread th1(get_int, std::ref(prom));
    std::thread th2(print_int, std::ref(fut));

    th1.join();
    th2.join();
    return 0;
}