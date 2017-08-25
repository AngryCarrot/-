#include "header.h"

class MinimalBST {
public:
	int buildMinimalBST(vector<int> vals) {
		// write code here
		// 有n个结点的二叉树，最小高度为log2(n)向上取整
		int result = (int)ceil(log(vals.size()) / log(2));
		return result;
	}
};