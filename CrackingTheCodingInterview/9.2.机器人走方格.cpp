#include "header.h"

/*题目描述
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
测试样例：2,2
返回：2

题目描述
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。
注意这次的网格中有些障碍点是不能走的。
给定一个int[][] map(C++ 中为vector >),表示网格图，若map[i][j]为1则说明该点不是障碍点，否则则为障碍。
另外给定int x,int y，表示网格的大小。请返回机器人从(0,0)走到(x - 1,y - 1)的走法数，
为了防止溢出，请将结果Mod 1000000007。保证x和y均小于等于50
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
			// 第一行是否有障碍物，有障碍物的话，该位置的以后位置均不可达
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
			// 第一列是否有障碍物，有障碍物的话，该位置的以后位置均不可达
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