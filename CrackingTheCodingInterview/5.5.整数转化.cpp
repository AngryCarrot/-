#include "header.h"

/*��Ŀ����
��дһ��������ȷ����Ҫ�ı伸��λ�����ܽ�����Aת�������B��
������������int A��int B���뷵����Ҫ�ı����λ������
����������10,5
���أ�4*/

class Transform {
public:
	int calcCost(int A, int B) {
		// write code here
		int C = A ^ B;
		int c = 0;
		while (C)
		{
			++c;
			C = C & (C - 1);
		}
		return c;
	}
};