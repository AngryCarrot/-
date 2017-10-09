#include "header.h"

/*题目描述
请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
给定一个N阶方阵int[][](C++中为vector<vector><int>>)mat和矩阵的阶数n，请返回完成操作后的int[][]方阵(C++中为vector<vector><int>>)，保证n小于等于300，矩阵中的元素为int范围内。</int></vector></int></vector>
测试样例：
[[1,2,3],[0,1,2],[0,0,1]]
返回：[[0,0,3],[0,0,0],[0,0,0]]*/

class Clearer {
public:
	/** 请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
	[[1,2,3],[0,1,2],[0,0,1]]->[[0,0,3],[0,0,0],[0,0,0]]
	*/
	vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
		// write code here
		set<int> rows;
		set<int> cols;
		const size_t length = n;
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = 0; j < length; j++)
			{
				if (0 == mat[i][j])
				{
					rows.insert(i);
					cols.insert(j);
				}
			}
		}
		for (size_t i = 0; i < length; i++)
		{
			if (1 == rows.count(i))
			{
				for (int &item : mat[i])
				{
					item = 0;
				}
			}
			else
			{
				for (int item : cols)
				{
					mat[i][item] = 0;
				}
			}
		}
		return mat;
	}
};

int main7()
{
	return 0;
}