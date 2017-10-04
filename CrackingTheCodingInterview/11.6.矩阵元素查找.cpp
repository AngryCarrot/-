#include "header.h"

/*题目描述
有一个NxM的整数矩阵，矩阵的行和列都是从小到大有序的。请设计一个高效的查找算法，查找矩阵中元素x的位置。
给定一个int有序矩阵mat，同时给定矩阵的大小n和m以及需要查找的元素x，请返回一个二元数组，代表该元素的行号和列号(均从零开始)。
保证元素互异。
测试样例：[[1,2,3],[4,5,6]],2,3,6
返回：[1,2]*/

class Finder {
public:
	vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
		// write code here
		vector<int> results;
		if (n == 0 || m == 0)
		{
			return results;
		}
		int i = 0;
		int j = m - 1;
		while (i < n && j >= 0)
		{
			if (mat[i][j] == x)
			{
				results.push_back(i);
				results.push_back(j);
				break;
			}
			else
			{
				if (mat[i][j] < x)
				{
					++i;
				}
				else
				{
					--j;
				}
			}
		}
		return results;
	}
};


int main11_6()
{
	return 0;
}