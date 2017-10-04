#include "header.h"

/*
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
����������
"(()())",6
���أ�true
����������
"()a()()",7
���أ�false
����������
"()(()()",7
���أ�false*/

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