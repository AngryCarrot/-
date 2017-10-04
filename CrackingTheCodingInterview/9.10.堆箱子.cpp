#include "header.h"

/*
��Ŀ����
��һ�����ӣ�ÿ�����ӿ�Ϊwi����Ϊdi����Ϊhi��������Ҫ�����Ӷ���������
����Ϊ��ʹ�����������Ӳ�������������ӵĿ�Ⱥͳ��ȱ���С����������ӡ�
��ʵ��һ������������ܶѳ�����ߵĸ߶ȣ�����ĸ߶ȼ����������������ӵĸ߶�֮�͡�
��������int����w,l,h���ֱ��ʾÿ�����ӿ����͸ߣ�ͬʱ�������ӵ���Ŀn��
�뷵���ܶѳɵ���ߵĸ߶ȡ���֤nС�ڵ���500��
����������
[1,1,1],[1,1,1],[1,1,1]
���أ�1
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