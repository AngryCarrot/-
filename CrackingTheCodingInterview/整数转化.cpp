#include "header.h"

/*
��Ŀ����
��дһ��������ȷ����Ҫ�ı伸��λ�����ܽ�����Aת�������B��
������������int A��int B���뷵����Ҫ�ı����λ������
*/
class Transform {
public:
	int calcCost(int A, int B) {
		// write code here
		int n = A ^ B;
		int count = 0;
		while (n)
		{
			++count;
			n &= (n - 1);
		}
		return count;
	}
};