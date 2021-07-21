#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point
{
    double x, y;
};
double getDistance(Point x, Point y)
{
    return sqrt(pow((x.x - y.x), 2) + pow((x.y - y.y), 2));
}
double Y_Coordinates(double x, double y, double k, double x0)
{
    return k * x0 - k * x + y;
}
//获取圆心
void getCircleCentor(Point p1, Point p2, Point &center1, Point &center2, double dRadius)
{
    double k = 0.0, k_verticle = 0.0;
    double mid_x = 0.0, mid_y = 0.0;
    double a = 1.0;
    double b = 1.0;
    double c = 1.0;
    k = (p2.y - p1.y) / (p2.x - p1.x);
    if (k == 0)
    {
        center1.x = (p1.x + p2.x) / 2.0;
        center2.x = (p1.x + p2.x) / 2.0;
        center1.y = p1.y + sqrt(dRadius * dRadius - (p1.x - p2.x) * (p1.x - p2.x) / 4.0);
        center2.y = p2.y - sqrt(dRadius * dRadius - (p1.x - p2.x) * (p1.x - p2.x) / 4.0);
    }
    else
    {
        k_verticle = -1.0 / k;
        mid_x = (p1.x + p2.x) / 2.0;
        mid_y = (p1.y + p2.y) / 2.0;
        a = 1.0 + k_verticle * k_verticle;
        b = -2 * mid_x - k_verticle * k_verticle * (p1.x + p2.x);
        c = mid_x * mid_x + k_verticle * k_verticle * (p1.x + p2.x) * (p1.x + p2.x) / 4.0 -
            (dRadius * dRadius - ((mid_x - p1.x) * (mid_x - p1.x) + (mid_y - p1.y) * (mid_y - p1.y)));

        center1.x = (-1.0 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        center2.x = (-1.0 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        center1.y = Y_Coordinates(mid_x, mid_y, k_verticle, center1.x);
        center2.y = Y_Coordinates(mid_x, mid_y, k_verticle, center2.x);
    }
    cout << center1.x << "    " << center1.y << endl;
    cout << center2.x << "    " << center2.y << endl;
}
//判断两点构成的线段是否是边界线段
void isEdge(vector<Point> originPt, vector<Point> res, double R)
{
    for (int i = 0; i < originPt.size(); i++)
    {
        Point C1, C2;
        for (int j = i + 1; j < originPt.size(); j++)
        {
            //无法满足构成圆的条件
            if (getDistance(originPt[i], originPt[j]) > 2 * R)
                continue;
            if (sqrt((originPt[i].x - originPt[j].x) * (originPt[i].x - originPt[j].x) + (originPt[i].y - originPt[j].y) * (originPt[i].y - originPt[j].y)) == 0.0)
                continue;
            //圆心获取
            getCircleCentor(originPt[i], originPt[j], C1, C2, R);
            //根据i,j两点所构成弦及alphs半径求得两个圆心
            //逐点扫描点集是否在任意一个圆内
            //若有一个圆内不包含任何数据点，则为边界
            bool oneCircle = false, anotherCircle = false;
            for (int m = 0; m < originPt.size(); m++)
            {
                if (m == i || m == j)
                    continue;
                if (!oneCircle && getDistance(originPt[m], C1) < R)
                    oneCircle = true;
                if (!anotherCircle && getDistance(originPt[m], C2) < R)
                    anotherCircle = true;
                //两个圆内都有数据点，则跳出
                if (oneCircle && anotherCircle)
                    break;
            }
            //任意一个不包含数据点，则更新边界集合
            if (!oneCircle || !anotherCircle)
            {
                res.emplace_back(originPt[i]);
                res.emplace_back(originPt[j]);
            }
        }
    }
}
int main()
{
    cout << "alpha shapes" << endl;
    Point a = {-1.0, -1.0};
    Point b = {1.0, 1.0};
    Point C1, C2;
    double r = sqrt(4);
    getCircleCentor(a, b, C1, C2, r);
    return 0;
}