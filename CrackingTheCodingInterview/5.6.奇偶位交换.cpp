#include "header.h"

/*��Ŀ����
���д���򽻻�һ�����Ķ����Ƶ�����λ��ż��λ����ʹ��Խ�ٵ�ָ��Խ�ã�
����һ��int x���뷵�ؽ��������int��
����������
10
���أ�5*/


class Exchange {
public:
	int exchangeOddEven(int x) {
		// write code here
		int odds = (x & 0xaaaaaaaa) >> 1;
		int even = (x & 0x55555555) << 1;
		return odds | even;
	}
};

