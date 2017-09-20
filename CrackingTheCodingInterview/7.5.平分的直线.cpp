#include "header.h"


struct Point {
	int x;
	int y;
	Point() :
		x(0), y(0) {
	}
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	}
};
/*
在二维平面上，有两个正方形，请找出一条直线，能够将这两个正方形对半分。假定正方形的上下两条边与x轴平行。
给定两个vecotrA和B，分别为两个正方形的四个顶点。请返回一个vector，代表所求的平分直线的斜率和截距，保证斜率存在。
测试样例：[(0,0),(0,1),(1,1),(1,0)],[(1,0),(1,1),(2,0),(2,1)]
返回：[0.0，0.5]
*/
class Bipartition 
{
public:
	//所求直线肯定经过两个正方形的中心点，利用两个中心点的坐标求出斜率与截距即可
	vector<double> getBipartition(vector<Point> A, vector<Point> B) 
	{
		// write code here
		vector<double> result(2, 0.0f);
		if ((A[0].y == B[0].y) && (A[2].y == B[2].y))
		{
			result[0] = 0;
			result[1] = (A[2].y + A[0].y) / 2.0;
			return result;
		}
		int x1 = (A[1].x + A[0].x) / 2;
		int y1 = (A[2].y + A[0].y) / 2;
		int x2 = (B[1].x + B[0].x) / 2;
		int y2 = (B[2].y + B[0].y) / 2;
		result[0] = (y2 - y1) * 1.0 / (x2 - x1);
		result[1] = y1 - result[0] * x1;
		return result;
	}
};

int main7_5()
{
	return 0;
}