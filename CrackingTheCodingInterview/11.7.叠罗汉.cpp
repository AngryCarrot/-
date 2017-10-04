#include "header.h"

/*��Ŀ����
���޺���һ����������Ϸ����Ϸ��һ����Ҫվ����һ���˵ļ���ϡ�ͬʱ����Ӧ����������˱�������˸���һ�㡣
��֪�μ���Ϸ��ÿ���˵���ߣ����д�������ͨ��ѡ�������Ϸ���ˣ����Ƕ��ܵ����ٸ��ˡ�
ע��������˶����Ⱥ󵽵ģ���ζ�Ųμ���Ϸ���˵��Ⱥ�˳����ԭ�����е�˳��Ӧ��һ�¡�
����һ��int����men��������������ÿ���˵���ߡ�ͬʱ����������n���뷵������ܵ�����������֤nС�ڵ���500��
����������[1,6,2,5,3,4],6
���أ�4*/

/* �������Ŀ�о������������
��Ŀ����
���޺���һ����������Ϸ����Ϸ��һ����Ҫվ����һ���˵ļ���ϡ�
Ϊ��ʹ���ɵ��޺����ȹ̣�����Ӧ����������˱�������˸���һ�㡣
����һ����Ϸ��Ҫ���������Ŀ��Ϊ���Ӿ�Ч�������ǻ�Ҫ��������˵���߱�������˸ߡ�
���дһ���㷨����������ܵ������ˣ�ע������������Ա��ͬʱ���֡�
����һ����άint������actors��ÿ��Ԫ��������ֵ���ֱ����һ����Ա����ߺ����ء�
ͬʱ������Ա����n���뷵������ܵ�����������֤������С�ڵ���500��
����������[[1,2],[3,4],[5,6],[7,8]],4
���أ�4*/

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