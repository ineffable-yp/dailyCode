#include <iostream>

#define MKSTR(x) #x
#define CONCAT(x, y) x##y

using namespace std;

int main()
{
    int xy = 100;
    cout << MKSTR(helloc) << endl;                      //形如"helloc"
    cout << CONCAT(x, y) << endl;                       //形如xy
    cout << "Value of __LINE__ : " << __LINE__ << endl; //所在行号
    cout << "Value of __FILE__ : " << __FILE__ << endl; //文件名
    cout << "Value of __DATE__ : " << __DATE__ << endl; //日期
    cout << "Value of __TIME__ : " << __TIME__ << endl; //时间
}