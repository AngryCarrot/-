#include "header.h"

/*有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
测试样例：
1024，19，2，6
返回：1100
*/

/*
该问题的解决可以分为三大步骤
1. 将N的第j到i之间的位清零
2. 对M进行移位操作，使之与j-i之间的位对齐
3. 合并M与N
*/
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		//int result = m + n;
		return n | m;
	}

	int binInsertNB(int n, int m, int i, int j)
	{
		// 创建掩码，用来清除N中从i到j的位
		int allOnes = ~0; // 一连串的1

		// 在位置j之前的位全部为1,其余为0
		int left = allOnes << (j + 1);

		// 在位置i之后的位均为1，
		int right = ((1 << i) - 1);

		// 除去j到i之间的位为0，其余位均为1
		int mask = left | right;

		// 清除位置j到i之间的位，然后将m放进去
		int n_cleared = n & mask;
		int m_shifted = m << i;
		return n_cleared | m_shifted;
	}
};

