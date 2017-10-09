#include "header.h"

/*题目描述
假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
测试样例：
"Hello world","worldhello "
返回：false
"waterbottle","erbottlewat"
返回：true*/

/*假设s2由s1旋转而成，在旋转时，将s1切成x和y两部分，并将其重新组合成s2,
但是无论x和y之间的且分店在什么地方，s2=yx肯定是yxyx=s1s1的子串，即s2总是s1s1的子串。*/

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