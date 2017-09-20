#include "header.h"

/*��Ŀ����
�и�С��������¥�ݣ�¥����n��̨�ף�С��һ�ο�����1�ס�2�ס�3�ס���ʵ��һ������������С���ж�������¥�ķ�ʽ��
Ϊ�˷�ֹ������뽫���Mod 1000000007
����һ��������int n���뷵��һ������������¥�ķ�ʽ������֤nС�ڵ���100000��
����������1
���أ�1*/
class GoUpstairs {
public:
	int countWays(int n) {
		// write code here
		vector<int> nums(n + 1, 0);
		nums[0] = 0;
		nums[1] = 1;
		nums[2] = 2;
		nums[3] = 4;
		for (int i = 4; i <= n; ++i)
		{
			nums[i] = ((nums[i - 1] + nums[i - 2]) % 1000000007 + nums[i - 3]) % 1000000007;
		}
		return nums[n];
	}
};

/*ע�⣺�����þ�����������������Һ��񲻻����*/

int main9_1()
{
	freopen("D:\\Workspace\\VSProject\\input.txt", "r", stdin);
	GoUpstairs sln;
	int n = 0;
	while (cin >> n)
	{
		cout << sln.countWays(n) << endl;
	}
	return 0;
}