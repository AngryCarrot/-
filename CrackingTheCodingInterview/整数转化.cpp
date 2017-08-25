#include "header.h"

/*
题目描述
编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
给定两个整数int A，int B。请返回需要改变的数位个数。
*/
class Transform {
public:
	int calcCost(int A, int B) {
		// write code here
		int n = A ^ B;
		int count = 0;
		while (n)
		{
			++count;
			n &= (n - 1);
		}
		return count;
	}
};