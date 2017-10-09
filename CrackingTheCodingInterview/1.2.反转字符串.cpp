#include "header.h"

class Reverse {
public:
	string reverseString(string iniString) {
		// write code here
		string strTemp = iniString;
		char* p = &strTemp[0];
		char* q = &strTemp[strTemp.length() - 1];
		while (p < q)
		{
			char c = *p;
			*p = *q;
			*q = c;
			++p;
			--q;
		}
		return strTemp;
	}
};

int main2()
{
	Reverse r;
	string str = "asdf";
	cout << r.reverseString(str) << endl;
	//getchar();
	return 0;
}