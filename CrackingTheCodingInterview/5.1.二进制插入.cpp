#include "header.h"

/*������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i-j+1��
����������
1024��19��2��6
���أ�1100
*/

/*
������Ľ�����Է�Ϊ������
1. ��N�ĵ�j��i֮���λ����
2. ��M������λ������ʹ֮��j-i֮���λ����
3. �ϲ�M��N
*/
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		//int result = m + n;
		return n | m;
	}

	int binInsertNB(int n, int m, int i, int j)
	{
		// �������룬�������N�д�i��j��λ
		int allOnes = ~0; // һ������1

		// ��λ��j֮ǰ��λȫ��Ϊ1,����Ϊ0
		int left = allOnes << (j + 1);

		// ��λ��i֮���λ��Ϊ1��
		int right = ((1 << i) - 1);

		// ��ȥj��i֮���λΪ0������λ��Ϊ1
		int mask = left | right;

		// ���λ��j��i֮���λ��Ȼ��m�Ž�ȥ
		int n_cleared = n & mask;
		int m_shifted = m << i;
		return n_cleared | m_shifted;
	}
};

