#include "header.h"

/*题目描述
请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的字符，并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
测试样例：
"Mr John Smith”,13
返回："Mr%20John%20Smith"

”Hello  World”,12
返回：”Hello%20%20World”*/

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
