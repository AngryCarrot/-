#include "header.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {	}
};

/*请实现一个函数，检查一棵二叉树是否为二叉查找树。
给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。*/
class Checker {
public:
	Checker() : prev(INT32_MIN) {}
	bool checkBST(TreeNode* root) {
		// write code here
		if (nullptr == root)
		{
			return true;
		}
		if (!checkBST(root->left))
		{
			return false;
		}
		if (root->val <= prev)
		{
			return false;
		}
		prev = root->val;
		if (!checkBST(root->right))
		{
			return false;
		}
		return true;
	}
private:
	int prev;
};
