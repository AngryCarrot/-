#include "header.h"

/*题目描述
有一个排过序的字符串数组，但是其中有插入了一些空字符串，请设计一个算法，找出给定字符串的位置。算法的查找部分的复杂度应该为log级别。
给定一个string数组str,同时给定数组大小n和需要查找的string x，请返回该串的位置(位置从零开始)。
测试样例：["a","b","","c","","d"],6,"c"
返回：3
*/

/*唯一的关注点是当str[mid] == ""时的处理，此时仅通过str[mid] == ""是无法判断目标位于mid左边还是右边。
所以需要向左走找到第一个不是空的位置，如果左边所有元素都为空，则直接令left = mid + 1;*/
class Finder {
public:
	int findString(vector<string> str, int n, string x) {
		// write code here
		int left = 0;
		int right = n - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (str[mid] == "")
			{
				int i = mid;
				while (i >= left && str[i].length() == 0)
				{
					--i;
				}
				if (i < left)
				{
					left = mid + 1;
				}
				else
				{
					if (str[i] == x)
					{
						return i;
					}
					else
					{
						if (str[i] < x)
						{
							left = mid + 1;
						}
						else
						{
							right = mid - 1;
						}
					}
				}
			}
			else
			{
				if (str[mid] == x)
				{
					return mid;
				}
				else
				{
					if (str[mid] < x)
					{
						left = mid + 1;
					}
					else
					{
						right = mid - 1;
					}
				}
			}
		}
		return -1;
	}
};

int main11_5()
{
	return 0;
}