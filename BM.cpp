#include <iostream>
#include <string>

using namespace std;

const int ASCIISIZE = 256;
// BM算法原理
// https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html

void preBmBc(string T, int m, int *bmBc)
{
    int i = 0;
    //初始化
    for (; i < ASCIISIZE; i++)
    {
        bmBc[i] = m;
    }
    for (i = 0; i < m - 1; i++)
    {
        //T[i]-->int ascii值
        //当字符重复出现时，以最右端字符到尾部的距离为最终距离
        bmBc[T[i]] = m - i - 1;
    }
}
void suffixes(string T, int m, int *suff)
{
    int i, q;
    suff[m - 1] = m;
    for (i = m - 2; i >= 0; --i)
    {
        q = i;
        while (q >= 0 && T[i] == T[m - 1 - i + q])
        {
            --q;
        }
        suff[i] = i - q;
    }
}
void preBmGs(string T, int m, int bmGs[])
{
    int i, j, suff[m];
    suffixes(T, m, suff);
    for (i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    for (i = m - 1; i >= 0; --i)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; ++j)
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
    for (i = 0; i <= m - 2; ++i)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}
int BM(string Pattern, int n, string T, int m)
{
    //静态数组直接在栈上分配，不可返回（生存期在函数调用完结束）
    // new动态数组
    int bmBc[ASCIISIZE];
    int bmGs[m];
    //预处理
    preBmGs(T, m, bmGs);
    preBmBc(T, m, bmBc);

    /* Searching */
    int i, j = 0;
    while (j <= n - m)
    {
        for (i = m - 1; i >= 0 && T[i] == Pattern[i + j]; --i)
            ;
        if (i < 0)
        {
            // cout << j << endl;
            j += bmGs[0];
        }
        else
            j += max(bmGs[i], bmBc[Pattern[i + j]] - m + 1 + i);
    }
    return j;
}
int main()
{
    string T = "HERE IS A SIMPLE EXAMPLE";
    string P = "EXAMPLE";

    cout << "begin: " << BM(P, P.length(), T, T.length()) << endl;
    cout << T[BM(P, P.length(), T, T.length())] << endl;
    return 0;
}
/*
template <typename E, class T, class A, class S>
inline typename basic_fbstring<E, T, A, S>::size_type
basic_fbstring<E, T, A, S>::find(
    const value_type *needle,
    const size_type pos,
    const size_type nsize) const
{
    auto const size = this->size();
    // nsize + pos can overflow (eg pos == npos), guard against that by checking
    // that nsize + pos does not wrap around.
    if (nsize + pos > size || nsize + pos < pos)
    {
        return npos;
    }

    if (nsize == 0)
    {
        return pos;
    }
    // Don't use std::search, use a Boyer-Moore-like trick by comparing
    // the last characters first
    auto const haystack = data();
    auto const nsize_1 = nsize - 1;
    auto const lastNeedle = needle[nsize_1];

    // Boyer-Moore skip value for the last char in the needle. Zero is
    // not a valid value; skip will be computed the first time it's
    // needed.
    size_type skip = 0;

    const E *i = haystack + pos;
    auto iEnd = haystack + size - nsize_1;

    while (i < iEnd)
    {
        // Boyer-Moore: match the last element in the needle
        while (i[nsize_1] != lastNeedle)
        {
            if (++i == iEnd)
            {
                // not found
                return npos;
            }
        }
        // Here we know that the last char matches
        // Continue in pedestrian mode
        for (size_t j = 0;;)
        {
            assert(j < nsize);
            if (i[j] != needle[j])
            {
                // Not found, we can skip
                // Compute the skip value lazily
                if (skip == 0)
                {
                    skip = 1;
                    while (skip <= nsize_1 && needle[nsize_1 - skip] != lastNeedle)
                    {
                        ++skip;
                    }
                }
                i += skip;
                break;
            }
            // Check if done searching
            if (++j == nsize)
            {
                // Yay
                return i - haystack;
            }
        }
    }
    return npos;
}
*/