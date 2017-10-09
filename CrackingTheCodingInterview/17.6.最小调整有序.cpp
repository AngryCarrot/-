#include "header.h"

/*��Ŀ����
��һ���������飬���дһ���������ҳ�����m��n��ֻҪ��m��n֮���Ԫ���ź������������������ġ�
ע�⣺n-mӦ��ԽСԽ�ã�Ҳ����˵���ҳ�����������������С�
����һ��int����A������Ĵ�Сn���뷵��һ����Ԫ�飬�����������е������յ㡣
(ԭ����λ�ô�0��ʼ���,��ԭ�������򣬷���[0,0])����֤A��Ԫ�ؾ�Ϊ��������
����������[1,4,6,5,9,10],6
���أ�[2,3]*/

// ��һ����

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

		// �����ǰԪ��С��֮ǰ�����Ԫ�أ�˵����ǰԪ��Ӧ������[M, N]֮��
		// �ҵ�ǰԪ���ǵ�ǰ����±������Ԫ�����Ը���NΪ��ǰԪ���±�
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
		// �����ǰԪ�ش���֮ǰ����СԪ����˵������Ԫ��Ӧ����[M, N]������
		// �ҵ�ǰԪ���ǵ�ǰ��С�±������Ԫ�أ����Ը���MΪ��ǰԪ���±�
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
