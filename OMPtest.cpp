
#include <iostream>
#include <ctime>
#include <omp.h>
#include <thread>

using namespace std;

class HasPtrItem
{
public:
  //构造函数
  HasPtrItem() : d(new int(0))
  {
    cout << "construct " << ++n_cstr << endl;
  }
  //拷贝构造函数
  HasPtrItem(const HasPtrItem &h) : d(h.d)
  {
    cout << "copy construct " << ++c_cstr << endl;
  }
  HasPtrItem(HasPtrItem &&h) : d(h.d)
  {
    cout << "move construct " << ++m_cstr << endl;
  }
  //析构函数
  ~HasPtrItem()
  {
    cout << "deconstruct " << ++d_cstr << endl;
  }
  int *d;

  static int n_cstr;
  static int c_cstr;
  static int d_cstr;
  static int m_cstr;
};

int HasPtrItem::n_cstr = 0;
int HasPtrItem::d_cstr = 0;
int HasPtrItem::c_cstr = 0;
int HasPtrItem::m_cstr = 0;

HasPtrItem getTemp()
{
  HasPtrItem h;
  return h;
}

int main()
{
  int n = 1, k = 20;
  int num = 10;
  srand((int)time(0));

#pragma omp parallel for
  for (; n <= k; n++)
  {
    int index = (float)rand() / (RAND_MAX + 1) * num;
    cout << index << endl;
  }
  return 0;
}