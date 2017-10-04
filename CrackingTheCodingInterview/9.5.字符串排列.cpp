#include "header.h"

/*
��Ŀ����
��дһ��������ȷ��ĳ�ַ���������������ϡ�
����һ��string A��һ��int n,�����ַ������䳤�ȣ��뷵�����и��ַ����ַ������У���֤�ַ�������С�ڵ���11���ַ������ַ���Ϊ��дӢ���ַ��������е��ַ������ֵ���Ӵ�С����(���ϲ��ظ��ַ���)
����������
"ABC"
���أ�["CBA","CAB","BCA","BAC","ACB","ABC"]
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