#include "header.h"

/*
题目描述
请设计一种算法，解决著名的n皇后问题。这里的n皇后问题指在一个nxn的棋盘上放置n个棋子，使得每行每列和每条对角线上都只有一个棋子，求其摆放的方法数。
给定一个int n，请返回方法数，保证n小于等于15
测试样例：
1
返回：1
*/

class Queens {
public:
	int nQueens(int n) {
		// write code here
		int level = 0;
		int results = 0;
		vector<pair<int, int>> queens;
		DFS(n, level, results, queens);
		return results;
	}

	void DFS(const int n, int level, int& results, vector<pair<int, int>>& queens)
	{
		if (level >= n)
		{
			++results;
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (place(level, i, queens))
			{
				queens.emplace_back(make_pair(level, i));
				DFS(n, level + 1, results, queens);
				queens.pop_back();
			}
		}
	}
	// 当返回true时代表该位置可以放皇后
	bool place(const int i, const int j, vector<pair<int, int>>& queens)
	{
		for (auto row : queens)
		{
			if (row.first == i || row.second == j || abs(i - row.first) == abs(j - row.second))
			{
				return false;
			}
		}
		return true;
	}
};

int main9_9()
{
	freopen(INPUT.c_str(), "r", stdin);
	int n = 0;
	Queens sln;
	while (cin >> n)
	{
		cout << sln.nQueens(n) << endl;
	}
	return 0;
}