#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

struct point
{
	double x;
	double y;
};

void circle_center(point a, point b,double radius)
{
	point pc1,pc2;
	double T1 = (b.x*b.x - a.x*a.x + b.y*b.y - a.y*a.y) / (2 * (b.x - a.x));
	double T2 = (b.y - a.y) / (b.x - a.x);
	
	double A = T2*T2 + 1.0;
	double B = 2 * (a.x*T2 - T1*T2 - a.y);
	double C = a.x*a.x - 2 * T1*a.x + T1*T1 + a.y*a.y - radius*radius;
	
	pc1.y = (-B + sqrt(B*B - 4 * A*C)) / (2 * A);
	pc1.x = T1 - T2*pc1.y;
	pc2.y = (-B - sqrt(B*B - 4 * A*C)) / (2 * A);
	pc2.x = T1 - T2*pc2.y;
	cout << " 圆心1:" << pc1.x << "  " << pc1.y << endl;
	cout << " 圆心2:" << pc2.x << "  " << pc2.y << endl;
}
int main()
{
  point a = { -1.0, -1.0 };
	point b = { 1.0, 1.0 };
	double r = sqrt(4);
	circle_center(a, b, r);

	return 0;
}