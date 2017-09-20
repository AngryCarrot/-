#include "header.h"


/*在二维平面上，有一些点，请找出经过点数最多的那条线。
给定一个点集vector<point>p和点集的大小n,没有两个点的横坐标相等的情况,
请返回一个vector<double>，代表经过点数最多的那条直线的斜率和截距。*/
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

class Line
{
public:
	Line()
	{
		epsilon = 1E-6;
	}
	Line(Point& p1, Point&p2)
	{
		k = (p1.y - p2.y) * 1.0 / (p1.x - p2.x);
		b = p1.y - k * p1.x;
	}
	bool operator==(const Line& l2) const
	{
		return abs(this->k - l2.k) <= epsilon && (this->b - l2.b) <= epsilon;
	}
	~Line() {}
	/*double k() { return slope; }
	double b() { return bias; }*/

	double k;
	double b;
	double epsilon;
};

struct KeyHasher
{
	std::size_t operator()(const Line& l) const
	{
		return ((hash<double>()(l.k)
			^ (hash<double>()(l.b) << 1)) >> 1);
	}
};

class DenseLine {
public:
	pair<double, double> calcLine(const Point& p1, const Point& p2)
	{
		double k = (p1.y - p2.y) * 1.0 / (p1.x - p2.x);
		double b = p1.y - k * p1.x;
		return make_pair(k, b);
	}
	vector<double> getLine(vector<Point> p, int n) {
		// write code here
		map<pair<double, double>, int> counts;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (i != j)
				{
					counts[calcLine(p[i], p[j])]++;
				}
			}
		}
		vector<double> result(2, 0.0f);
		int maxCount = 0;
		for (auto item : counts)
		{
			if (item.second > maxCount)
			{
				maxCount = item.second;
				result[0] = item.first.first;
				result[1] = item.first.second;
			}
		}
		return result;		
	}
};

int main7_6()
{
	return 0;
}