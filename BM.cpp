#include <cstdio>
#include <cstdlib>
#include <iostream>

// BM算法原理
// https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
//https://icode9.com/content-1-1009160.html
using namespace std;
const int size = 256;
//将模式串字符使用hash表示
void generateBC(char b[], int m, int bc[])
{
    //b是模式串， m是模式串的长度， bc是散列表
    //bc的下标是字符集的ASCII码，数组值是每个字符在模式串中出现的位置。
    for (int i = 0; i < size; i++)
    {
        bc[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        int ascii = (int)b[i];
        bc[ascii] = i;
    }
}
/*
求suffix数组和prefix数组
suffix数组的下标K表示后缀字串的长度，数组值对应存储的是，在模式串中跟好后缀{u}相匹配的子串{u*}
的起始下标值。
prefix数组是布尔型。来记录模式串的后缀字串是否能匹配模式串的前缀子串。

*/
void generateGS(char b[], int m, int suffix[], bool prefix[])
{
    for (int i = 0; i < m; i++)
    {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        int j = i;
        int k = 0; //公共后缀字串长度
        while (j >= 0 && b[j] == b[m - 1 - k])
        {
            //与b[0, m-1]求公共后缀字串
            --j;
            ++k;
            suffix[k] = j + 1; //j+1表示公共后缀字串在b[0,i]中的起始下标
        }
        if (j == -1)
            prefix[k] = true; //如果公共后缀字串也是模式串的前缀字串
    }
}

//j表示坏字符对应的模式串中的字符下标，m是模式串的长度
//计算在好后缀规则下模式串向后移动的个数
int moveByGS(int j, int m, int suffix[], bool prefix[])
{
    int k = m - 1 - j; //好后缀的长度
    if (suffix[k] != -1)
        return j - suffix[k] + 1;
    for (int r = j + 2; r <= m - 1; ++r)
    {
        if (prefix[m - r] == true)
        {
            return r;
        }
    }
    return m;
}

//BM算法
int BM(char a[], int n, char b[], int m)
{
    int suffix[m];
    bool prefix[m];

    int bc[size]; //bc记录模式串中每个字符最后出现的位置

    generateBC(b, m, bc);             //构建字符串hash表
    generateGS(b, m, suffix, prefix); //计算好后缀和好前缀数组

    int i = 0; //表示主串与模式串对齐的第一个字符
    while (i <= n - m)
    {
        int j;
        for (j = m - 1; j >= 0; j--)
        { //模式串从后往前匹配
            if (a[i + j] != b[j])
                break; //坏字符对应的模式串下标是j,即i+j 位置是坏字符的位置si
        }
        if (j < 0)
        {
            return i; //匹配成功，返回主串与模式串第一个匹配的字符的位置
        }
        //这里x等同于将模式串往后滑动j-bc[(int)a[i+j]]位
        //bc[(int)a[i+j]]表示主串中坏字符在模式串中出现的位置xi
        int x = i + (j - bc[(int)a[i + j]]);

        int y = 0;
        if (j < m - 1)
        { //如果有好后缀的话,计算在此情况下向后移动的位数y
            y = moveByGS(j, m, suffix, prefix);
        }
        i = i + max(x, y); //i更新位可以后移较多的位置
    }
    return -1;
}

int main()
{
    char a[] = "aaaabaaba";
    char b[] = "aaaa";
    int i = BM(a, 9, b, 2);
    printf("%d\n", i);
    return 0;
}