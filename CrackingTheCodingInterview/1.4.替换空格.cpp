#include "header.h"

/*��Ŀ����
���дһ�����������ַ����еĿո�ȫ���滻Ϊ��%20�����ٶ����ַ������㹻�Ŀռ����������ַ�������֪���ַ�������ʵ����(С�ڵ���1000)��ͬʱ��֤�ַ����ɴ�Сд��Ӣ����ĸ��ɡ�
����һ��string iniString Ϊԭʼ�Ĵ����Լ����ĳ��� int len, �����滻���string��
����������
"Mr John Smith��,13
���أ�"Mr%20John%20Smith"

��Hello  World��,12
���أ���Hello%20%20World��*/

class Replacement {
public:
	string replaceSpace(string iniString, int length) {
		// write code here
		int spaceNo = 0;
		for_each(begin(iniString), end(iniString), [&spaceNo](char& c) {
			if (' ' == c)
			{
				++spaceNo;
			}
		});
		//cout << spaceNo << endl;
		int newLen = length + spaceNo * 2;
		char* newStr = new char[newLen+1];
		newStr[newLen] = '\0';
		int end = newLen - 1;
		for (int i = length - 1; i >= 0; --i)
		{
			if (' ' == iniString[i])
			{
				newStr[end--] = '0';
				newStr[end--] = '2';
				newStr[end--] = '%';
			}
			else
			{
				newStr[end--] = iniString[i];
			}			
		}
		string result = string(newStr);
		delete[] newStr;
		return result;
	}
};

int main4()
{
	Replacement rp;
	string str = "hello world ! This is nowCoder";
	cout << rp.replaceSpace(str, str.length()) << endl;
	getchar();
	return 0;
}
