#include "header.h"

/*
题目描述
请编写程序交换一个数的二进制的奇数位和偶数位。（使用越少的指令越好）
给定一个int x，请返回交换后的数int。
*/
class Exchange {
public:	
	int exchangeOddEven(int x) {
		// write code here
		// 用掩码10101010......10101010来提取奇数位，然后右移一位
		// 用掩码01010101......01010101来提取偶数位，然后左移一位
		// 两者或
		int odds = (x & 0xaaaaaaaa) >> 1;
		int even = (x & 0x55555555) << 1;
		return odds | even;
	}
};