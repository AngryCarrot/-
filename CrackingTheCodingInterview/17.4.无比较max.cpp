#include "header.h"

/*题目描述
请编写一个方法，找出两个数字中最大的那个。条件是不得使用if-else等比较和判断运算符。
给定两个int a和b，请返回较大的一个数。若两数相同则返回任意一个。
测试样例：1，2
返回：2*/


/*
一、c = (a - b) >> 31;
	（1）、若 a >= b;则c的符号位为0，右移过后结果为0；
	（2）、若 a < b;则c的符号位为1，右移高位补1，结果是-1而不是1
二、a = c * (a - b)
	（1）、当 c = 0;时，说明 a >= b;计算结果为a；
	（2）、当 c = 1;时，说明 a < b;计算结果为b；
*/

class Max {
public:
	int getMax(int a, int b) {
		// write code here
		int c = (a - b) >> 31;
		return a + c * (a - b);
	}
};

int main17_4()
{
	return 0;
}