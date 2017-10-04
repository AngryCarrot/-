#include "header.h"

/*��Ŀ����
���������޵�Ӳ�ң���ֵΪ25�֡�10�֡�5�ֺ�1�֣����д�������n���м��ֱ�ʾ����
����һ��int n���뷵��n���м��ֱ�ʾ������֤nС�ڵ���100000��Ϊ�˷�ֹ������뽫��Mod 1000000007��
����������6
���أ�2
*/

class Coins {
public:
	int countWays(int n) {
		// write code here
		vector<int> coins = { 1, 5, 10, 25 };
		int length = coins.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < length; ++i)
		{
			for (int j = coins[i]; j <= n; ++j)
			{
				dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
			}
		}
		return dp[n];
	} // dp[i]=��dp[i] + ��dp[i-coin] 
};

int main9_8()
{
	return 0;
}