#include "header.h"

/*
题目描述
有一堆箱子，每个箱子宽为wi，长为di，高为hi，现在需要将箱子都堆起来，
而且为了使堆起来的箱子不到，上面的箱子的宽度和长度必须小于下面的箱子。
请实现一个方法，求出能堆出的最高的高度，这里的高度即堆起来的所有箱子的高度之和。
给定三个int数组w,l,h，分别表示每个箱子宽、长和高，同时给定箱子的数目n。
请返回能堆成的最高的高度。保证n小于等于500。
测试样例：
[1,1,1],[1,1,1],[1,1,1]
返回：1
*/

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		return (a.first < b.first)
			|| ((a.first == b.first) && (a.second < b.second));
	}
};

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return (a.first < b.first)
		|| ((a.first == b.first) && (a.second < b.second));
}

class Box {
public:
	int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) 
	{
		// write code here
		int length = w.size();
		map<pair<int, int>, int, Compare> boxes;
		for (int i = 0; i < length; ++i)
		{
			auto p = make_pair(w[i], l[i]);
			boxes[p] = max(h[i], boxes[p]);
		}
		for (auto box : boxes)
		{
			//cout << "(" << box.first.first << ", " << box.first.second << ", " << box.second << ")" << endl;
		}
		
		vector<int> dp(length, 0);
		dp[0] = (*begin(boxes)).second;
		int lastMax = dp[0];
		vector<pair<pair<int, int>, int>> boxes2(begin(boxes), end(boxes));
		for (int i = 1; i < boxes2.size(); ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (boxes2[j].first.first < boxes2[i].first.first
					&& boxes2[j].first.second < boxes2[i].first.second)
				{
					dp[i] = dp[j] + boxes2[i].second;
					lastMax = max(lastMax, dp[i]);
				}
			}
		}
		return lastMax;
	}
};

int main9_10()
{
	freopen(INPUT.c_str(), "r", stdin);
	int n = 0;
	Box sln;
	while (cin >> n)
	{
		vector<int> w(n);
		vector<int> l(n);
		vector<int> h(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> w[i] >> l[i] >> h[i];
		}
		sln.getHeight(w, l, h, n);
	}
	return 0;
}