#include "header.h"

class MinimalBST {
public:
	int buildMinimalBST(vector<int> vals) {
		// write code here
		// ��n�����Ķ���������С�߶�Ϊlog2(n)����ȡ��
		int result = (int)ceil(log(vals.size()) / log(2));
		return result;
	}
};