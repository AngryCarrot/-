#include "header.h"

class Same {
public:
	bool checkSam(string stringA, string stringB) {
		// write code here
		if (stringA.length() != stringB.length())
		{
			return false;
		}
		sort(begin(stringA), end(stringA));
		sort(begin(stringB), end(stringB));
		return stringA == stringB;
	}
};

int main3()
{
	return 0;
}