#include "header.h"

/*
��Ŀ����
�����һ���㷨�����������n�ʺ����⡣�����n�ʺ�����ָ��һ��nxn�������Ϸ���n�����ӣ�ʹ��ÿ��ÿ�к�ÿ���Խ����϶�ֻ��һ�����ӣ�����ڷŵķ�������
����һ��int n���뷵�ط���������֤nС�ڵ���15
����������
1
���أ�1
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
	// ������trueʱ�����λ�ÿ��ԷŻʺ�
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