#include "header.h"


/*题目描述
有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，
例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],
现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。
给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。
测试样例：[6,1,2,3,4,5],6,6
返回：0*/


class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		int length = A.size();
		int left = 0;
		int right = length - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (A[mid] == x)
			{
				return mid;
			}
			else
			{
				if (A[mid] < x)
				{
					if (A[mid] < A[left] && x > A[right])
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
				else
				{
					if (A[mid] > A[left] && x < A[left])
					{
						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
			}
		}

		return -1;
	}

	int findElement2(vector<int> A, int n, int x) {
		// write code here
		int length = A.size();
		int left = 0;
		int right = length - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (A[mid] == x)
			{
				return mid;
			}
			else
			{
				if (A[mid] < x)
				{
					if (x < A[right] && A[right] < A[left])
					{
						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
				else
				{
					if (true);
				}
			}
		}
		return -1;
	}
};


int main11_3()
{
	FREOPEN;
	Finder sln;
	int N = 0;
	int x = 0;
	while (cin >> N >> x)
	{
		vector<int> A(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
		}
		sln.findElement(A, N, x);
	}
	return 0;
}