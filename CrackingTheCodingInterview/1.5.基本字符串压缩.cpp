#include "header.h"

/*题目描述
利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
给定一个string iniString为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
测试样例
"aabcccccaaa"
返回："a2b1c5a3"
"welcometonowcoderrrrr"
返回："welcometonowcoderrrrr"*/

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