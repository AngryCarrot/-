#include "header.h"

class AddSubstitution {
public:
	/*  ���дһ��������ʵ�������ĳ˷��������ͳ�������(����ĳ�ָ����)��ֻ����ʹ�üӺš�
		��������������int a,int b,ͬʱ����һ��int type������������ͣ�
		1Ϊ��a �� b��
		0Ϊ��a �� b��
		-1Ϊ��a �� b��
		�뷵�ؼ���Ľ������֤���ݺϷ��ҽ��һ����int��Χ�ڡ�*/
	int calc(int a, int b, int type) {
		// write code here
		int result = 0;
		// �˷���b��a���
		if (type == 1)
		{
			int sum = 0;
			for (int i = 0; i < b; ++i)
			{
				sum += a;
			}
			result = sum;
		}
		// ������c��b��ӣ��ʹ���a����c-1������
		if (type == 0)
		{
			int sum = 0;
			int r = 0;
			while (sum <= a)
			{
				sum += b;
				r += 1;
			}
			result = r - 1;
		}
		// �������ҵ�һ����ֵd��ʹ��b + d = a
		if (type == -1)
		{
			int diff = 0;
			while (diff + b != a)
			{
				++diff;
			}
			result = diff;
		}

		return result;
	};
};

int main7_4()
{
	AddSubstitution sln;
	cout << sln.calc(1, 2, 1) << endl;
	return 0;
}