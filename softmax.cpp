#include <iostream>
#include <cmath>
using namespace std;

/*
** attention 带权求和
*/
//y = 1/(1+e(-x))指数
float sigmoid(float x)
{
    return (1 / (1 + exp(-x)));
}

//softmax 归一化
void softmax(float *x, int row, int column)
{
    for (int j = 0; j < row; ++j)
    {
        float max = 0.;
        float sum = 0.;
        for (int k = 0; k < column; ++k)
            if (max < x[k + j * column]) //x[j][k]
                max = x[k + j * column];
        for (int k = 0; k < column; ++k)
        {
            x[k + j * column] = exp(x[k + j * column] - max);
            sum += x[k + j * column];
        }

        for (int k = 0; k < column; ++k)
            x[k + j * column] /= sum;
    }
}
int returnMore(int *A, int n)
{
    int res = A[0], cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] == res)
            ++cnt;
        else
            --cnt;
        if (cnt == 0)
        {
            res = A[i];
            cnt = 1;
        }
    }
    cout << res << endl;
    return 0;
}
int main()
{
    int A[] = {2,
               4,
               2,
               5,
               2,
               6, 2};
    returnMore(A, 7);
    return 0;
}