#include "header.h"

/*
��Ŀ����
���д���򽻻�һ�����Ķ����Ƶ�����λ��ż��λ����ʹ��Խ�ٵ�ָ��Խ�ã�
����һ��int x���뷵�ؽ��������int��
*/
class Exchange {
public:	
	int exchangeOddEven(int x) {
		// write code here
		// ������10101010......10101010����ȡ����λ��Ȼ������һλ
		// ������01010101......01010101����ȡż��λ��Ȼ������һλ
		// ���߻�
		int odds = (x & 0xaaaaaaaa) >> 1;
		int even = (x & 0x55555555) << 1;
		return odds | even;
	}
};