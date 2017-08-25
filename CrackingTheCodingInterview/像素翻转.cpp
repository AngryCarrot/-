#include "header.h"

class Transform {
public:	
	/*
	[[1,2,3],
	 [4,5,6],
	 [7,8,9]]
	[[7,4,1],
	 [8,5,2],
	 [9,6,3]]
	*/
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		// write code here
		size_t length = n;
		for (size_t i = 0; i < length; i++)
		{
			for (size_t j = i; j < length; j++)
			{
				if (i != j)
				{
					swap(mat[i][j], mat[j][i]);
				}
			}
		}
		for (size_t i = 0; i < length; i++)
		{
			reverse(begin(mat[i]), end(mat[i]));
		}
		return mat;
	}
};

int main6()
{
	//Transform z;
	
	return 0;
}