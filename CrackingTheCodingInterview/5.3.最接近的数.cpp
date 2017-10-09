#include "header.h"

/*题目描述
有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
测试样例：2
返回：[1,4]*/

/*给定一个数n和两个位置i和j，假设将位i从1翻到0，位j从0翻到1。
若i>j，n就会减小；若i<j，则n就会变大。*/

/*想让这个数变大，必须反转最右边的0，且它的右边必须还有个1，记该位置为p
数出p右方有多少个1，将位置0到位置p的所有位清零，然后回填c1-1个1，假设c1为p右方1的个数，c0为p右方0的个数。*/

/*或者数出多少个1，分别从x-1和x+1开始找到第一个1的个数与其相等的数即可。*/

class CloseNumber {
public:
	vector<int> getCloseNumber(int x) {
		// write code here
		vector<int> r(2, 0);
		r[0] = getPrev(x);
		r[1] = getNext(x);
		return r;
	}

	int getNext(int n)
	{
		/* 计算c0与c1 */
		int c = n;
		int c0 = 0;
		int c1 = 0;
		while (((c & 1) == 0) && (c != 0))
		{
			++c0;
			c >>= 1;
		}

		while ((c & 1) == 1)
		{
			++c1;
			c >>= 1;
		}

		if (c0 + c1 == 31 || c0 + c1 == 0)
		{
			return -1;
		}

		int p = c0 + c1; //最右边非拖尾的0的位置

		n |= (1 << p); // 翻转最右边，非拖尾的0
		n &= ~((1 << p) - 1); // 将p右方的所有位清零
		n |= (1 << (c1 - 1)) - 1; // 在右方插入c1-1个1
		return n;
	}

	int getPrev(int n)
	{
		int temp = n;
		int c0 = 0;
		int c1 = 0;
		while (temp & 1 == 1)
		{
			++c1;
			temp >>= 1;
		}

		if (temp == 0)
		{
			return -1;
		}

		while (((temp & 1) == 0) && (temp != 0))
		{
			++c0;
			temp >>= 1;
		}

		int p = c0 + c1;
		n &= ((~0) << (p + 1));

		int mask = (1 << (c1 + 1)) - 1;
		n |= mask << (c0 - 1);

		return n;
	}
};