#include "header.h"

/*题目描述
有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶、3阶。请实现一个方法，计算小孩有多少种上楼的方式。
为了防止溢出，请将结果Mod 1000000007
给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
测试样例：1
返回：1*/
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

/*注意：可以用矩阵快速幂来做，但我好像不会算基*/

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