#include "header.h"

/*
题目描述
编写一个方法，确定某字符串的所有排列组合。
给定一个string A和一个int n,代表字符串和其长度，请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，排列中的字符串按字典序从大到小排序。(不合并重复字符串)
测试样例：
"ABC"
返回：["CBA","CAB","BCA","BAC","ACB","ABC"]
*/

class Permutation {
public:
	vector<string> getPermutation(string A) {
		// write code here
		vector<string> results;
		string current;
		vector<bool> used(A.length(), false);
		this->getPermutationHelper(A, current, used, results);
		sort(results.rbegin(), results.rend());
		return results;
	}
	void getPermutationHelper(
		const string& A, 
		string& current,
		vector<bool>& used,
		vector<string>& resSet)
	{
		if (current.length() == A.length())
		{
			resSet.emplace_back(current);
		}
		for (int i = 0; i < A.length(); ++i)
		{
			if (!used[i])
			{
				used[i] = true;
				current.push_back(A[i]);
				getPermutationHelper(A, current, used, resSet);
				current.pop_back();
				used[i] = false;
			}
		}
	}
};

int main9_5()
{
	return 0;
}