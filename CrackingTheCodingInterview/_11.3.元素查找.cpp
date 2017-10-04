#include "header.h"


/*��Ŀ����
��һ���Ź�������飬����n����������������������������һ�����ȵ���λ��
���磬ԭ����Ϊ[1,2,3,4,5,6]��������λ5��λ�ü������[6,1,2,3,4,5],
���ڶ�����λ������飬��Ҫ����ĳ��Ԫ�ص�λ�á������һ�����Ӷ�Ϊlog������㷨����������
����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
����������[6,1,2,3,4,5],6,6
���أ�0*/


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