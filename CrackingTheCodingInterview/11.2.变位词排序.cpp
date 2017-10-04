#include "header.h"

/*
题目描述
请编写一个方法，对一个字符串数组进行排序，将所有变位词合并，保留其字典序最小的一个串。这里的变位词指变换其字母顺序所构成的新的词或短语。例如"triangle"和"integral"就是变位词。
给定一个string的数组str和数组大小int n，请返回排序合并后的数组。保证字符串串长小于等于20，数组大小小于等于300。
测试样例：
["ab","ba","abc","cba"]
返回：["ab","abc"]
*/

class SortString {
public:
	vector<string> sortStrings(vector<string>& str, int n) {
		// write code here
		map<vector<int>, string> m;
		for (string& s : str)
		{
			vector<int> f(128, 0);
			for (char c : s)
			{
				f[c]++;
			}
			if (m.find(f) == end(m))
			{
				m[f] = s;
			}
			else
			{
				m[f] = min(m[f], s);
			}
		}
		vector<string> results;
		for (auto item : m)
		{
			results.emplace_back(item.second);
		}
		
		sort(begin(results), end(results));
		return results;
	}
};

int main11_2()
{
	FREOPEN;
	int n;
	string s;
	SortString sln;
	while (cin >> n)
	{
		vector<string> str(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> str[i];
		}
		sln.sortStrings(str, n);
	}
	return 0;
}