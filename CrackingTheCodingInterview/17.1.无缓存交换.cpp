#include "header.h"

/*��Ŀ����
���дһ�������������ڲ�ʹ���κ���ʱ������ֱ�ӽ�����������ֵ��
����һ��int����AB��������Ԫ�غ͵�һ��Ԫ��Ϊ��������ֵ���뷵�ؽ���������顣
����������[1,2]
���أ�[2,1]*/

class Exchange {
public:
	vector<int> exchangeAB(vector<int> AB) {
		// write code here
		AB[0] = AB[0] ^ AB[1];
		AB[1] = AB[0] ^ AB[1];
		AB[0] = AB[0] ^ AB[1];
		return AB;
	}
};

int main17_1()
{
	return 0;
}