#include "header.h"


class Joseph {
public:	
	/*题目描述
	约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。
	然后由第一个人开始报数，数到m的人出局。现在需要求的是最后一个出局的人的编号。
	给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。
	测试样例：5 3
	返回：4
	*/
	int getResult(int n, int m) 
	{
		list<int> people;
		for (int i = 1; i <= n; ++i)
		{
			people.emplace_back(i);
		}
		auto iter = begin(people);
		while (people.size() > 1)
		{
			for (int i = 1; i < m; ++i)
			{
				++iter;
				if (iter == end(people))
				{
					iter = begin(people);
				}
			}
			cout << *iter << endl;
			iter = people.erase(iter);
			iter = iter == end(people) ? begin(people) : iter;
		}
		return people.back();
	}

	/*
	令f[n]表示当有n个候选人时，最后当选者的编号。
	f[1] = 0
	f[n] = (f[n - 1] + K) mod n
	现在先将n个人按照编号进行排序：
	0 1 2 3 ... n-1
	那么第一次被淘汰的人编号一定是K-1(假设K < n，若K > n则为(K-1) mod n)。将被选中的人标记为"#"：
	0 1 2 3 ... K-2 # K K+1 K+2 ... n-1
	第二轮报数时，起点为K这个候选人。并且只剩下n-1个选手。假如此时把k+1看作0'，k+2看作1'...
	则对应有：
	0     1 2 3 ... K-2  #   K  K+1 K+2 ... n-1
	n-K'            n-2'     0'  1'  2' ... n-K-1'
	此时在0',1',...,n-2'上再进行一次K报数的选择。而f[n-1]的值已经求得，因此我们可以直接求得当选者的编号s'。
	但是，该编号s'是在n-1个候选人报数时的编号，并不等于n个人时的编号，所以我们还需要将s'转换为对应的s。
	通过观察，s和s'编号相对偏移了K，又因为是在环中，因此得到s = (s'+K) mod n。
	即f[n] = (f[n-1] + k) mod n。
	*/
	int getResultNB(int n, int m) {
		// write code here
		vector<int> dp(n + 1);
		dp[1] = 0;
		for (int i = 2; i <= n; ++i)
		{
			dp[i] = (dp[i - 1] + m) % i;
		}
		return dp[n] + 1;
	}

	/*
	约瑟夫问题是一个著名的趣题。这里我们稍稍修改一下规则。有n个人站成一列。
	并从头到尾给他们编号，第一个人编号为1。然后从头开始报数，第一轮依次报1，2，1，2...然后报到2的人出局。
	接着第二轮再从上一轮最后一个报数的人开始依次报1，2，3，1，2，3...报到2，3的人出局。
	以此类推直到剩下以后一个人。现在需要求的即是这个人的编号。
	给定一个int n，代表游戏的人数。请返回最后一个人的编号
	测试样例：5
	返回：5
	*/
	int getResult(int n) {
		// write code here

	}
};

int main10()
{
	FREOPEN;
	Joseph sln;
	int n = 0;
	int m = 0;
	while (cin >> n >> m)
	{
		cout << sln.getResult(n, m) << endl;
	}
	return 0;
}