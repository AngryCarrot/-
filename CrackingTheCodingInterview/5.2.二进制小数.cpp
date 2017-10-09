#include "header.h"

/*题目描述
有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
测试样例：0.625
返回：0.101*/

class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		if (num >= 1 || num <= 0)
		{
			return "Error";
		}
		string binary = "0.";
		while (num > 0)
		{
			if (binary.length() > 32)
			{
				return "Error";
			}
			else
			{
				num *= 2;
				if (num >= 1)
				{
					binary.append("1");
					num -= 1;
				}
				else
				{
					binary.append("0");
				}
			}
		}
		return binary;
	}
	string printBin2(double num) {
		// write code here
		if (num >= 1 || num <= 0)
		{
			return "Error";
		}
		string binary = "0.";
		double frac = 0.5f;
		while (num > 0)
		{
			if (binary.length() > 32)
			{
				return "Error";
			}
			else
			{
				if (abs(num - frac) >= 1E-6)
				{
					binary.append("1");
					num -= frac;
				}
				else
				{
					binary.append("0");
				}
				frac /= 2;
			}
		}
		return binary;
	}
};

int main5_2()
{
	FREOPEN;
	BinDecimal sln;
	double num = 0.0f;
	while (cin >> num)
	{
		sln.printBin(num);
	}
	return 0;
}