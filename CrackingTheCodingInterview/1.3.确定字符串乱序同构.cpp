#include "header.h"

/*��Ŀ����
���������ַ��������д����ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ���������涨��СдΪ��ͬ�ַ����ҿ����ַ����ص�ո�
����һ��string stringA��һ��string stringB���뷵��һ��bool�����������Ƿ��������к����ͬ����֤�����ĳ��ȶ�С�ڵ���5000��
����������
"This is nowcoder","is This nowcoder"
���أ�true
"Here you are","Are you here"
���أ�false*/

class Same {
public:
	bool checkSam(string stringA, string stringB) {
		// write code here
		if (stringA.length() != stringB.length())
		{
			return false;
		}
		sort(begin(stringA), end(stringA));
		sort(begin(stringB), end(stringB));
		return stringA == stringB;
	}
	// ����2���ж������ַ����ĸ����ַ������Ƿ����
};

int main3()
{
	return 0;
}