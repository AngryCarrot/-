#include "header.h"

/*
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false*/

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> stk;
		for (char c : A)
		{
			if (c == '(')
			{
				stk.push(c);
			}
			else
			{
				if (c == ')')
				{
					if (stk.empty())
					{
						return false;
					}
					stk.pop();
				}
				else
				{
					return false;
				}
			}
		}
		return stk.empty();
	}
};

int main9_6()
{
	freopen(INPUT.c_str(), "r", stdin);
	Parenthesis sln;
	string A;
	while (cin >> A)
	{
		cout << sln.chkParenthesis(A, A.length()) << endl;
	}
	return 0;
}