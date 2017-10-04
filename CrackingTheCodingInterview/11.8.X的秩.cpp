#include "header.h"

/*��Ŀ����
��������Ҫ����һ������ͬʱҪ���ڶ���ÿ������ʱ����������ȣ����ڵ�ǰ������С�ڵ����������ĸ���(������������)��
�����һ����Ч�����ݽṹ���㷨��ʵ��������ܡ�
����һ��int����A��ͬʱ�������Ĵ�Сn���뷵��һ��int���飬Ԫ��Ϊÿ�μ���������ȡ�
��֤�����СС�ڵ���5000��
����������[1,2,3,4,5,6,7],7
���أ�[0,1,2,3,4,5,6]*/

// ����map���������ʣ����м���ͳ�ơ�
// ţ�Ƶ��˿����Լ�ʵ��AVL��������һ��Ľṹ

class Rank {
public:
	vector<int> getRankOfNumber(vector<int> A, int n) {
		// write code here
		vector<int> results;
		map<int, int> ranks;
		for (int a : A)
		{
			++ranks[a];
			int num = -1;
			for (auto iter = begin(ranks); iter != (++ranks.find(a)); ++iter)
			{
				num += iter->second;
			}
			results.emplace_back(num);
		}
		return results;
	}
};


int main11_8()
{
	FREOPEN;
	Rank sln;
	int n = 0;
	while (cin >> n)
	{
		vector<int> A(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		sln.getRankOfNumber(A, n);
	}
	return 0;
}