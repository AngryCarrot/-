#include "header.h"


/*��Ŀ����
��һ�������������������������飬��ǰ��һ�����ں���һ�����֣����������������һ������ԡ�
�����һ����Ч���㷨��������������е�����Ը�����
����һ��int����A�����Ĵ�Сn���뷵��A�е�����Ը�������֤nС�ڵ���5000��
����������[1,2,3,4,5,6,7,0],8
���أ�7*/


/*
1. ��11.8һ�������ȵĻ����϶Ե����ż���
2. ð���������˶��ٴν��������ж��ٸ������
3. �鲢�����ڶ���������merge��ͬʱ����¼����
4. �������
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