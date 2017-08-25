#include "header.h"

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