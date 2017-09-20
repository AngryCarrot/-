#include "header.h"

/*��Ŀ����
��һ��XxY������һ��������ֻ���߸����ֻ�����һ������ߣ�Ҫ�����Ͻ��ߵ����½ǡ������һ���㷨������������ж������߷���
��������������int x,int y���뷵�ػ����˵��߷���Ŀ����֤x��yС�ڵ���12��
����������2,2
���أ�2

��Ŀ����
��һ��XxY������һ��������ֻ���߸����ֻ�����һ������ߣ�Ҫ�����Ͻ��ߵ����½ǡ������һ���㷨������������ж������߷���
ע����ε���������Щ�ϰ����ǲ����ߵġ�
����һ��int[][] map(C++ ��Ϊvector >),��ʾ����ͼ����map[i][j]Ϊ1��˵���õ㲻���ϰ��㣬������Ϊ�ϰ���
�������int x,int y����ʾ����Ĵ�С���뷵�ػ����˴�(0,0)�ߵ�(x - 1,y - 1)���߷�����
Ϊ�˷�ֹ������뽫���Mod 1000000007����֤x��y��С�ڵ���50
*/
class Robot {
public:
	int countWays(int x, int y) {
		// write code here
		vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
		for (int i = 1; i <= x; ++i)
		{
			for (int j = 1; j <= y; ++j)
			{
				if (i == 1 || j == 1)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}				
			}
		}
		return dp[x][y];
	}
	int countWays(vector<vector<int> > map, int x, int y) {
		// write code here
		vector<vector<int>> dp(x, vector<int>(y, 0));
		dp[0][0] = map[0][0] == 1 ? 1 : 0;
		if (dp[0][0] == 0)
		{
			return 0;
		}
		for (int i = 1; i < x; ++i)
		{
			// ��һ���Ƿ����ϰ�����ϰ���Ļ�����λ�õ��Ժ�λ�þ����ɴ�
			if (map[i][0] != 1)
			{
				dp[i][0] = 0;
				for (int j = i + 1; j < x; ++j)
				{
					dp[j][0] = 0;
				}
				break;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
			}
		}
		for (int i = 1; i < y; ++i)
		{
			// ��һ���Ƿ����ϰ�����ϰ���Ļ�����λ�õ��Ժ�λ�þ����ɴ�
			if (map[0][i] != 1)
			{
				dp[0][i] = 0;
				for (int j = i + 1; j < y; ++j)
				{
					dp[0][j] = 0;
				}
				break;
			}
			else
			{
				dp[0][i] = dp[0][i - 1];
			}
		}
		for (int i = 1; i < x; ++i)
		{
			for (int j = 1; j < y; j++)
			{
				if (map[i][j] != 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
					
				}
			}
		}
		return dp[x - 1][y - 1];
	}
};

int main9_2()
{
	freopen("D:\\Workspace\\VSProject\\input.txt", "r", stdin);
	int x = 0;
	int y = 0;
	Robot sln;
	while (cin >> x >> y)
	{
		sln.countWays(x, y);
	}
	vector<vector<int>> map = { {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 0, 1, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1 } };
	x = 11;
	y = 4;
	sln.countWays(map, x, y);
	return 0;
}