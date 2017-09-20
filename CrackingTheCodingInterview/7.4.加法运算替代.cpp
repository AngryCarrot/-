#include "header.h"

class AddSubstitution {
public:
	/*  请编写一个方法，实现整数的乘法、减法和除法运算(这里的除指整除)。只允许使用加号。
		给定两个正整数int a,int b,同时给定一个int type代表运算的类型，
		1为求a ＊ b，
		0为求a ／ b，
		-1为求a － b。
		请返回计算的结果，保证数据合法且结果一定在int范围内。*/
	int calc(int a, int b, int type) {
		// write code here
		int result = 0;
		// 乘法：b个a相加
		if (type == 1)
		{
			int sum = 0;
			for (int i = 0; i < b; ++i)
			{
				sum += a;
			}
			result = sum;
		}
		// 除法：c个b相加，和大于a，则c-1就是商
		if (type == 0)
		{
			int sum = 0;
			int r = 0;
			while (sum <= a)
			{
				sum += b;
				r += 1;
			}
			result = r - 1;
		}
		// 减法：找到一个差值d，使得b + d = a
		if (type == -1)
		{
			int diff = 0;
			while (diff + b != a)
			{
				++diff;
			}
			result = diff;
		}

		return result;
	};
};

int main7_4()
{
	AddSubstitution sln;
	cout << sln.calc(1, 2, 1) << endl;
	return 0;
}