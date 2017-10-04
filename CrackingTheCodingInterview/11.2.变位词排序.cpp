#include "header.h"

/*
��Ŀ����
���дһ����������һ���ַ�������������򣬽����б�λ�ʺϲ����������ֵ�����С��һ����������ı�λ��ָ�任����ĸ˳�������ɵ��µĴʻ�������"triangle"��"integral"���Ǳ�λ�ʡ�
����һ��string������str�������Сint n���뷵������ϲ�������顣��֤�ַ�������С�ڵ���20�������СС�ڵ���300��
����������
["ab","ba","abc","cba"]
���أ�["ab","abc"]
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