#include "header.h"

/*��Ŀ����
�����ַ��ظ����ֵĴ�������дһ��������ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ�����aabcccccaaa����ѹ�����ɡ�a2b1c5a3������ѹ������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ�����
����һ��string iniStringΪ��ѹ���Ĵ�(����С�ڵ���10000)����֤�����ַ����ɴ�СдӢ����ĸ��ɣ�����һ��string��Ϊ�����ѹ�����δ�仯�Ĵ���
��������
"aabcccccaaa"
���أ�"a2b1c5a3"
"welcometonowcoderrrrr"
���أ�"welcometonowcoderrrrr"*/

class Zipper {
public:
	string zipString(string iniString) {
		// write code here
		const size_t length = iniString.length();
		if (1 >= length)
		{
			return iniString;
		}
		string result = "";
		
		for (size_t i = 0; i < length; )
		{
			int count = 1;
			size_t j = i + 1;
			for (; j < length; ++j)
			{
				if (iniString[j] == iniString[i])
				{
					++count;
				}
				else
				{
					break;
				}
			}
			result = result + iniString[i] + to_string(count);
			i = j;
		}
		if (length <= result.length())
		{
			return iniString;
		}
		return result;
	}
};

int main5()
{
	Zipper z;
	string str;
	while (cin >> str)
	{
		string x = z.zipString(str);
		cout << x << endl;
	}
	return 0;
}