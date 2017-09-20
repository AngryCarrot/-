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
�ڶ�άƽ���ϣ������������Σ����ҳ�һ��ֱ�ߣ��ܹ��������������ζ԰�֡��ٶ������ε�������������x��ƽ�С�
��������vecotrA��B���ֱ�Ϊ���������ε��ĸ����㡣�뷵��һ��vector�����������ƽ��ֱ�ߵ�б�ʺͽؾ࣬��֤б�ʴ��ڡ�
����������[(0,0),(0,1),(1,1),(1,0)],[(1,0),(1,1),(2,0),(2,1)]
���أ�[0.0��0.5]
*/
class Bipartition 
{
public:
	//����ֱ�߿϶��������������ε����ĵ㣬�����������ĵ���������б����ؾ༴��
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