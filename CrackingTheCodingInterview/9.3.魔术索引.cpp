#include "header.h"

/*
题目描述
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。
给定一个升序数组，元素值各不相同，编写一个方法，判断在数组A中是否存在魔术索引。
请思考一种复杂度优于o(n)的方法。
给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
测试样例：[1,2,3,4,5]
返回：false
*/
/*
题目描述
在数组A[0..n-1]中，有所谓的魔术索引，满足条件A[i]=i。
给定一个不下降序列，元素值可能相同，编写一个方法，判断在数组A中是否存在魔术索引。
请思考一种复杂度优于o(n)的方法。
给定一个int数组A和int n代表数组大小，请返回一个bool，代表是否存在魔术索引。
测试样例：[1,1,3,4,5]
返回：true
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

	// 需要搜索左右两边
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