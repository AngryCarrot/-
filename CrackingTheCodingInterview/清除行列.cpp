#include "header.h"

class Clearer {
public:
	/** ���дһ���㷨����N�׷�����ĳ��Ԫ��Ϊ0���������ڵ����������㡣
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