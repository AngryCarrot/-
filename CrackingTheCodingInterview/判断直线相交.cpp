#include "header.h"

/*
��Ŀ����
����ֱ������ϵ�ϵ�����ֱ�ߣ�ȷ��������ֱ�߻᲻���ཻ��
�߶���б�ʺͽؾ����ʽ��������double s1��double s2��double y1��double y2���ֱ����ֱ��1��2��б��(��s1,s2)�ͽؾ�(��y1,y2)���뷵��һ��bool���������������ֱ���Ƿ��ཻ��������ֱ���غ�Ҳ��Ϊ�ཻ��
����������
3.14,3.14,1,2
���أ�false
*/
class CrossLine {
public:
	bool checkCrossLine(double s1, double s2, double y1, double y2) {
		// write code here
		return !(abs(s1 - s2) <= 1e-6 && abs(y1 - y2) <= 1e-6);
	}
};

// ֻ��б����ͬ���ؾ಻ͬ�Ż��ཻ