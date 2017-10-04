#include "header.h"


/*题目描述
有一组数，对于其中任意两个数组，若前面一个大于后面一个数字，则这两个数字组成一个逆序对。
请设计一个高效的算法，计算给定数组中的逆序对个数。
给定一个int数组A和它的大小n，请返回A中的逆序对个数。保证n小于等于5000。
测试样例：[1,2,3,4,5,6,7,0],8
返回：7*/


/*
1. 和11.8一样，在秩的基础上对调符号即可
2. 冒泡排序，做了多少次交换，就有多少个逆序对
3. 归并排序，在对有序数组merge的同时，记录数量
4. 暴力求解
*/


class AntiOrder {
public:
	int countBubbleSort(vector<int>& A, int n) 
	{
		int results = 0;
		for (int i = n; i >= 0; --i)
		{
			for (int j = 1; j < i; ++j)
			{
				if (A[j - 1] > A[j])
				{
					++results;
					swap(A[j], A[j - 1]);
				}
			}
		}
		return results;
	}


	int countMergeSort(vector<int>& A, int n) {
		// write code here
		int results = 0;

		results = mergeSort(A, 0, n - 1);

		return results;
	}
	int mergeSort(vector<int>& A, int left, int right)
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;
			int a = mergeSort(A, left, mid);
			int b = mergeSort(A, mid + 1, right);
			return a + b + merge(A, left, mid, right);
		}
		return 0;
	}
	int merge(vector<int>& A, int left, int mid, int right)
	{
		vector<int> temp(right - left + 1);
		int i = left;
		int j = mid + 1;
		int k = 0;
		int count = 0;
		while (i <= mid && j <= right)
		{
			if (A[i] > A[j])
			{
				count += mid - i + 1;
				temp[k++] = A[j++];
			}
			else
			{
				temp[k++] = A[i++];
			}
		}
		while (i <= mid)
		{
			temp[k++] = A[i++];
		}
		while (j <= right)
		{
			temp[k++] = A[j++];
		}
		for (i = left, k = 0; i <= right; ++i, ++k)
		{
			A[i] = temp[k];
		}
		return count;
	}
};

int main11_9()
{
	FREOPEN;
	AntiOrder sln;
	int n = 0;
	while (cin >> n)
	{
		vector<int> A(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		sln.countBubbleSort(A, n);
	}
}