#include "header.h"

/*
���յ�ɵ����Ŀ�����һ���������յ�Ļ������ʱ���·��һ���� n-1 + m - 1 = n + m - 2.��Ƥ��λ������������

��Ŀ����
��һ��nxm������״�ĳ����ﱬ���˺�ˮ����ˮ��(0,0)�ĸ�������������У�
������������еĸ�����һЩ��������ˮֻ����û�н����ĸ���������
�뷵�غ�ˮ����(n - 1,m - 1)������ʱ��(��ˮֻ�ܴ�һ���������������ڵĸ����Һ�ˮ��λʱ���ܴ�һ�������������ڸ���)��
����һ������map��ʾ���У�����map[i][j]��ʾ����Ϊ(i,j)�ĸ��ӣ�ֵΪ1����ø����н�����0����û�н�����
ͬʱ��������Ĵ�Сn��m(n��m��С�ڵ���100)���뷵������(n - 1,m - 1)������ʱ�䡣
��֤��ˮһ���������յ㡣
*/

class Flood {
public:
	int floodFill(vector<vector<int> > map, int n, int m) {
		// write code here		
		if (map[0][0] == 1)
		{
			return 0;
		}
		vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
		dp[0][0] = 0;
		for (int i = 1; i < m; ++i)
		{
			if (map[0][i] == 1)
			{
				break;
			}
			else
			{
				dp[0][i] = dp[0][i - 1] + 1;
			}			
		}
		for (int i = 1; i < n; ++i)
		{
			if (map[i][0] == 1)
			{
				break;
			}
			else
			{
				dp[i][0] = dp[i - 1][0] + 1;
			}
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				if (map[i][j - 1] == 0 || map[i - 1][j] == 0)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
					/*dp[i][j] = min(
						map[i-1][j] == 0 ? dp[i - 1][j] : INT_MAX, 
						map[i][j-1] == 0 ? dp[i][j - 1] : INT_MAX) + 1;*/
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};

int main9_7()
{
	return 0;
}