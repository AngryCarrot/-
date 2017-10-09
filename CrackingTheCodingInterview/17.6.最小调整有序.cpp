#include "header.h"

/*题目描述
有一个整数数组，请编写一个函数，找出索引m和n，只要将m和n之间的元素排好序，整个数组就是有序的。
注意：n-m应该越小越好，也就是说，找出符合条件的最短序列。
给定一个int数组A和数组的大小n，请返回一个二元组，代表所求序列的起点和终点。
(原序列位置从0开始标号,若原序列有序，返回[0,0])。保证A中元素均为正整数。
测试样例：[1,4,6,5,9,10],6
返回：[2,3]*/

// 差一错误

class Rearrange {
public:
	vector<int> findSegment(vector<int>& A, int n) {
		// write code here
		int leftEnd = findEndOfLeft(A, 0);
		if (leftEnd == n - 1)
		{
			return { 0, 0 };
		}
		
		int rightStart = findStartOfRight(A, n - 1);
		
		int max;
		int min;
		if (leftEnd + 1 == rightStart)
		{
			max = *(max_element(begin(A) + leftEnd, begin(A) + rightStart + 1));
			min = *(min_element(begin(A) + leftEnd, begin(A) + rightStart + 1));
		}
		else
		{
			max = *(max_element(begin(A) + leftEnd + 1, begin(A) + rightStart));
			min = *(min_element(begin(A) + leftEnd + 1, begin(A) + rightStart));
		}

		int left = shrinkLeft(A, leftEnd, min);
		int right = shrinkRight(A, rightStart, max);

		return { left, right };
	}

	int findEndOfLeft(const vector<int>& A, int i)
	{
		int n = A.size();
		while (i < n - 1)
		{
			if (A[i] <= A[i + 1])
			{
				++i;
			}
			else
			{
				break;
			}
		}
		return i;
	}

	int findStartOfRight(const vector<int>& A, int j)
	{
		while (j > 0)
		{
			if (A[j] >= A[j - 1])
			{
				--j;
			}
			else
			{
				break;
			}
		}
		return j;
	}

	int shrinkLeft(const vector<int>& A, int le, int min)
	{
		int i = 0;
		for (; i <= i; ++i)
		{
			if (A[i] > min)
			{
				break;
			}
		}
		return i;
	}

	int shrinkRight(const vector<int>& A, int rs, int max)
	{
		int j = A.size() - 1;
		for (; j >= rs; --j)
		{
			if (A[j] < max)
			{
				break;
			}
		}
		return j;
	}


	vector<int> findSegmentNB(vector<int>& A, int n) {
		// write code here
		int M = 0;
		int N = 0;

		// 如果当前元素小于之前的最大元素，说明当前元素应当处于[M, N]之间
		// 且当前元素是当前最大下标的无序元素所以更新N为当前元素下标
		int max = A[0];
		for (int i = 1; i < n; ++i)
		{
			if (A[i] >= max)
			{
				max = A[i];
			}
			else
			{
				N = i;
			}
		}
		// 如果当前元素大于之前的最小元素则说明当期元素应处于[M, N]序列中
		// 且当前元素是当前最小下标的无序元素，所以更新M为当前元素下标
		int min = A[n - 1];
		for (int j = n - 2; j >= 0; --j)
		{
			if (A[j] <= min)
			{
				min = A[j];
			}
			else
			{
				M = j;
			}
		}
		return { M, N };
	}
};



int main()
{
	FREOPEN;
	Rearrange sln;
	int n = 0;
	while (cin >> n)
	{
		vector<int> nums(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		sln.findSegmentNB(nums, n);
	}
	return 0;
}
