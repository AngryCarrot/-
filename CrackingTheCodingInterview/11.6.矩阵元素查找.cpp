#include "header.h"

/*��Ŀ����
��һ��NxM���������󣬾�����к��ж��Ǵ�С��������ġ������һ����Ч�Ĳ����㷨�����Ҿ�����Ԫ��x��λ�á�
����һ��int�������mat��ͬʱ��������Ĵ�Сn��m�Լ���Ҫ���ҵ�Ԫ��x���뷵��һ����Ԫ���飬�����Ԫ�ص��кź��к�(�����㿪ʼ)��
��֤Ԫ�ػ��졣
����������[[1,2,3],[4,5,6]],2,3,6
���أ�[1,2]*/

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