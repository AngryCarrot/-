#include "header.h"

/*题目描述
请编写一个方法，返回某集合的所有非空子集。 
给定一个int数组A和数组的大小int n，请返回A的所有非空子集。
保证A的元素个数小于等于20，且元素互异。各子集内部从大到小排序,子集之间字典逆序排序，见样例。 
测试样例： [123,456,789]
返回：{[789,456,123],[789,456],[789,123],[789],[456 123],[456],[123]}*/

class Subset {
public:
	vector<vector<int> > getSubsets(vector<int>& A, int n) {
		// write code here
		sort(begin(A), end(A), greater<int>());
		vector<vector<int>> results(1, vector<int>());
		for (int item : A)
		{
			int size = results.size();
			for (int i = 0; i < size; ++i)
			{
				vector<int> tmp = results[i];
				tmp.emplace_back(item);
				results.emplace_back(tmp);
			}
		}
		results.erase(begin(results));
		sort(begin(results), end(results), compare);
			//[](const vector<int>& a, const vector<int>& b) { return a[0] > b[0] || a.size() > b.size(); });
		return results;
	}
	static bool compare(const vector<int>& a, const vector<int>& b)
	{
		int length = min(a.size(), b.size());
		for (int i = 0; i < length; ++i)
		{
			if (a[i] == b[i])
			{
				continue;
			}
			else
			{
				if (a[i] > b[i])
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return a.size() > b.size();
	}
};

int main9_4()
{
	freopen(INPUT.c_str(), "r", stdin);
	Subset sln;
	int n = 0;
	while (cin >> n)
	{
		vector<int> A(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> A[i];
		}
		auto results = sln.getSubsets(A, n);
		for (auto item : results)
		{
			for (auto i : item)
			{
				cout << i << " ";
			}
			cout << endl;
		}
	}
	return 0;
}