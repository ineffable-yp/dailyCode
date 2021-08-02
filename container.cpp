#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <tuple>
#include <memory>

using namespace std;
void foo(std::shared_ptr<int> i)
{
    (*i)++;
}
auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>
    if (id == 0)
        return std::make_tuple(3.8, 'A', "张三");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "李四");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "王五");
    return std::make_tuple(0.0, 'D', "null");
    // 如果只写 0 会出现推断错误, 编译失败
}

int main()
{
    array<int, 4> arr = {1, 2, 3, 4};
    vector<int> v;
    v.emplace_back(2);
    v.emplace_back(3);

    cout << "size: " << v.size() << " capacity:" << v.capacity() << endl;
    v.emplace_back(2);
    v.emplace_back(4);
    v.emplace_back(2);
    cout << "size: " << v.size() << " capacity:" << v.capacity() << endl;

    v.clear();
    cout << "size: " << v.size() << " capacity:" << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "size: " << v.size() << " capacity:" << v.capacity() << endl;

    sort(arr.begin(), arr.end(), [](int a, int b) -> bool
         { return b < a; });

    for (auto &i : arr)
        cout << *(&i) << endl;

    auto student = get_student(0);
    cout << "ID: 0, "
         << "GPA:  " << get<0>(student) << ", "
         << "成绩: " << get<1>(student) << ", "
         << "姓名: " << get<2>(student) << '\n';
    auto pointer = make_shared<int>(10);
    foo(pointer);
    cout << *pointer << endl;
    auto pointer2 = pointer;
    auto pointer3 = pointer;
    cout << pointer.use_count() << endl;
    pointer2.reset();
    cout << pointer2.use_count() << endl;
    cout << pointer3.use_count() << endl;
    return 0;
}