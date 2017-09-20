#include "header.h"

/*
��Ŀ����
������A[0..n-1]�У�����ν��ħ����������������A[i]=i��
����һ���������飬Ԫ��ֵ������ͬ����дһ���������ж�������A���Ƿ����ħ��������
��˼��һ�ָ��Ӷ�����o(n)�ķ�����
����һ��int����A��int n���������С���뷵��һ��bool�������Ƿ����ħ��������
����������[1,2,3,4,5]
���أ�false
*/
/*
��Ŀ����
������A[0..n-1]�У�����ν��ħ����������������A[i]=i��
����һ�����½����У�Ԫ��ֵ������ͬ����дһ���������ж�������A���Ƿ����ħ��������
��˼��һ�ָ��Ӷ�����o(n)�ķ�����
����һ��int����A��int n���������С���뷵��һ��bool�������Ƿ����ħ��������
����������[1,1,3,4,5]
���أ�true
*/
class MagicIndex {
public:
	bool findMagicIndex(vector<int>& A, int n) {
		// write code here
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (A[mid] == mid)
			{
				return true;
			}
			else
			{
				if (A[mid] < mid)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return false;
	}

	// ��Ҫ������������
	bool findMagicIndex(vector<int> A, int n) {
		// write code here
		return findMagic(A, 0, n - 1);
	}
	bool findMagic(vector<int>& A, int left, int right)
	{
		if (left > right)
		{
			return false;
		}
		int mid = left + (right - left) / 2;
		if (A[mid] == mid)
		{
			return true;
		}
		else
		{
			return findMagic(A, left, mid - 1) || findMagic(A, mid + 1, right);
		}
	}
};

int main9_3()
{
	freopen(INPUT.c_str(), "r", stdin);
	MagicIndex sln;
	int n = 0;
	while (cin >> n)
	{
		vector<int> nums(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		sln.findMagicIndex(nums, n);
	}
}