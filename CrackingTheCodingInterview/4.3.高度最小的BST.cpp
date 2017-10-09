#include "header.h"

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {	}
};


class MinimalBST {
public:
	int buildMinimalBST(vector<int> vals) {
		// write code here
		// ��n�����Ķ���������С�߶�Ϊlog2(n)����ȡ��
		int result = (int)ceil(log(vals.size()) / log(2));
		return result;
	}

	TreeNode* createMinimalBST(vector<int>& vals)
	{
		return createMinimalBST(vals, 0, vals.size() - 1);
	}
	TreeNode* createMinimalBST(vector<int>& vals, int left, int right)
	{
		if (left < right)
		{
			return nullptr;
		}
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(vals[mid]);
		root->left = createMinimalBST(vals, left, mid - 1);
		root->right = createMinimalBST(vals, mid + 1, right);
		return root;
	}
};