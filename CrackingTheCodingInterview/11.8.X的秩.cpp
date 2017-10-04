#include "header.h"

/*题目描述
现在我们要读入一串数，同时要求在读入每个数的时候算出它的秩，即在当前数组中小于等于它的数的个数(不包括它自身)，
请设计一个高效的数据结构和算法来实现这个功能。
给定一个int数组A，同时给定它的大小n，请返回一个int数组，元素为每次加入的数的秩。
保证数组大小小于等于5000。
测试样例：[1,2,3,4,5,6,7],7
返回：[0,1,2,3,4,5,6]*/

// 利用map的有序性质，进行计数统计。
// 牛逼的人可以自己实现AVL树或红黑树一类的结构

class Rank {
public:
	vector<int> getRankOfNumber(vector<int> A, int n) {
		// write code here
		vector<int> results;
		map<int, int> ranks;
		for (int a : A)
		{
			++ranks[a];
			int num = -1;
			for (auto iter = begin(ranks); iter != (++ranks.find(a)); ++iter)
			{
				num += iter->second;
			}
			results.emplace_back(num);
		}
		return results;
	}
};


int main11_8()
{
	FREOPEN;
	Rank sln;
	int n = 0;
	while (cin >> n)
	{
		vector<int> A(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		sln.getRankOfNumber(A, n);
	}
	return 0;
}