#include "header.h"

/*��Ŀ����
�ٶ����Ƕ�֪���ǳ���Ч���㷨�����һ�������Ƿ�Ϊ�����ַ������Ӵ����뽫����㷨��д��һ�����������������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ�Ҫ��ֻ�ܵ���һ�μ���Ӵ��ĺ�����
���������ַ���s1,s2,�뷵��boolֵ����s2�Ƿ���s1��ת���ɡ��ַ������ַ�ΪӢ����ĸ�Ϳո����ִ�Сд���ַ�������С�ڵ���1000��
����������
"Hello world","worldhello "
���أ�false
"waterbottle","erbottlewat"
���أ�true*/

/*����s2��s1��ת���ɣ�����תʱ����s1�г�x��y�����֣�������������ϳ�s2,
��������x��y֮����ҷֵ���ʲô�ط���s2=yx�϶���yxyx=s1s1���Ӵ�����s2����s1s1���Ӵ���*/

class ReverseEqual {
public:
	bool checkReverseEqual(string s1, string s2) {
		// write code here
		int length1 = s1.length();
		int length2 = s2.length();
		if (length1 != length2)
		{
			return false;
		}
		string str = s1 + s1;
		if (string::npos == str.find(s2))
		{
			return false;
		}
		return true;
	}
};

int main8()
{
	return 0;
}