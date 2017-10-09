#include "header.h"

/*��Ŀ����
��һ������0��1֮���ʵ��������Ϊdouble���������Ķ����Ʊ�ʾ������������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ء�Error����
����һ��double num����ʾ0��1��ʵ�����뷵��һ��string����������Ķ����Ʊ�ʾ���ߡ�Error����
����������0.625
���أ�0.101*/

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