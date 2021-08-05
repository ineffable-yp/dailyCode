#include <iostream>
//有利于编译器优化
//1.移动构造函数
//2.移动分配函数
//3.析构函数
//4.叶子函数
void may_throw()
{
    throw true;
}
auto non_block_throw = []
{
    may_throw();
};
void no_throw() noexcept
{
    return;
}

auto block_throw = []() noexcept
{
    no_throw();
};
int main()
{
    std::cout << std::boolalpha
              << "may_throw() noexcept? " << noexcept(may_throw()) << std::endl
              << "no_throw() noexcept? " << noexcept(no_throw()) << std::endl
              << "lmay_throw() noexcept? " << noexcept(non_block_throw()) << std::endl
              << "lno_throw() noexcept? " << noexcept(block_throw()) << std::endl;
    return 0;
}