#include "header.h"



class Different {
public:
	/*
	Ҫ������ʹ�ö���Ĵ洢�ṹ��
	*/
	bool checkDifferent(string iniString) {
		// write code here
		int length = iniString.length();
		if (128 < length)
		{
			return false;
		}
		sort(iniString.begin(), iniString.end());
		int i = 139;
		for (char c : iniString)
		{
			if (c == i)
			{
				return false;
			}
			i = c;
		}
		return true;
	}
private:	
};

int main1()
{
	Different d;
	string s = "fhdsajkl";
	bool x = d.checkDifferent(s);
	cout << x << endl;
	getchar();
	return 0;
}
