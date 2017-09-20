#include "header.h"

/*题目描述
有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。
给定一个数int k，请返回第k个数。保证k小于等于100。
测试样例： 3
返回：7
*/

class KthNumber {
public:
	int findKth(int k) {
		// write code here
		vector<int> threes;
		vector<int> fives;
		vector<int> sevens;
		threes.emplace_back(3);
		fives.emplace_back(5);
		sevens.emplace_back(7);
		int result = 0;
		for (int i = 0; i < k; ++i)
		{
			result = min(min(threes[0], fives[0]), sevens[0]);
			if (threes[0] == result)
			{
				threes.erase(begin(threes));
			}
			if (fives[0] == result)
			{
				fives.erase(begin(fives));
			}
			if (sevens[0] == result)
			{
				sevens.erase(begin(sevens));
			}

			threes.emplace_back(result * 3);
			fives.emplace_back(result * 5);
			sevens.emplace_back(result * 7);

		}
		return result;
	}
};

int main7_7()
{
	FILE* file;
	freopen("D:\\Workspace\\VSProject\\input.txt", "r", stdin);
	KthNumber sln;
	int n = 0;
	while (cin >> n)
	{
		cout << sln.findKth(n) << endl;
	}
	return 0;
}