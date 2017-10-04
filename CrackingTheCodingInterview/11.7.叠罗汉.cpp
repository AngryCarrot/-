#include "header.h"

/*题目描述
叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。同时我们应该让下面的人比上面的人更高一点。
已知参加游戏的每个人的身高，请编写代码计算通过选择参与游戏的人，我们多能叠多少个人。
注意这里的人都是先后到的，意味着参加游戏的人的先后顺序与原序列中的顺序应该一致。
给定一个int数组men，代表依次来的每个人的身高。同时给定总人数n，请返回最多能叠的人数。保证n小于等于500。
测试样例：[1,6,2,5,3,4],6
返回：4*/

/* 这个鬼题目感觉有问题的样子
题目描述
叠罗汉是一个著名的游戏，游戏中一个人要站在另一个人的肩膀上。
为了使叠成的罗汉更稳固，我们应该让上面的人比下面的人更轻一点。
现在一个马戏团要表演这个节目，为了视觉效果，我们还要求下面的人的身高比上面的人高。
请编写一个算法，计算最多能叠多少人，注意这里所有演员都同时出现。
给定一个二维int的数组actors，每个元素有两个值，分别代表一个演员的身高和体重。
同时给定演员总数n，请返回最多能叠的人数。保证总人数小于等于500。
测试样例：[[1,2],[3,4],[5,6],[7,8]],4
返回：4*/

class Stack {
public:
	int getHeight(vector<int>& men, int n) {
		// write code here
		vector<int> dp(n, 1);
		dp[0] = 1;
		int results = 0;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (men[i] > men[j])
				{
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
			results = max(dp[i], results);
		}
		return results;
	}

	int getHeight(vector<vector<int> > actors, int n) {
		// write code here
		sort(begin(actors), end(actors));
		vector<int> dp(n, 1);
		int result = 0;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (actors[j][0] < actors[i][0] && actors[j][1] < actors[i][1])
				{
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
			result = max(dp[i], result);
		}
		return result;
	}
	static bool cmp(vector<int>& a, vector<int>& b)
	{
		return (a[0] > b[0] && a[1] > b[1]) || (a[0] == b[0] && a[1] > b[1]) || (a[1] == b[1] && a[0] > b[0]);
	}
};


int main11_7()
{
	FREOPEN;
	Stack sln;
	int n = 0;
	while (cin >> n)
	{
		vector<vector<int>> actors(n, vector<int>(2));
		for (int i = 0; i < n; ++i)
		{
			cin >> actors[i][0] >> actors[i][1];
		}
		sln.getHeight(actors, n);
	}
	return 0;
}