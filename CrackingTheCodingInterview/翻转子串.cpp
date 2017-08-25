#include "header.h"

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