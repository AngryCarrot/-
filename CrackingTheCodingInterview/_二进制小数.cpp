#include "header.h"

/*��һ������0��1֮���ʵ��������Ϊdouble���������Ķ����Ʊ�ʾ������������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ء�Error����
����һ��double num����ʾ0��1��ʵ�����뷵��һ��string����������Ķ����Ʊ�ʾ���ߡ�Error����
����������
0.625
���أ�0.101
*/
class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		string result = "0.";
		string str = to_string(num);
		
		return str;
	}
};

int main()
{
	BinDecimal bd;
	cout << bd.printBin(0.987658) << endl;
	getchar();
	return 0;
}