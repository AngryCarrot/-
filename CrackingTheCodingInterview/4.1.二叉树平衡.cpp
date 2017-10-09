#pragma once
#include "header.h"

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {	}
};

class Balance {
public:
	bool isBalance(TreeNode* root) {
		// write code here
		bool isBalanced = true;
		this->getDepth(root, isBalanced);
		return isBalanced;
	}
private:
	int getDepth(TreeNode* root, bool& isBalanced)
	{
		if (nullptr == root)
		{
			return 0;
		}
		int lDepth = this->getDepth(root->left, isBalanced);
		int rDepth = this->getDepth(root->right, isBalanced);
		if (abs(lDepth - rDepth) > 1)
		{
			isBalanced = false;
		}
		return 1 + max(lDepth, rDepth);
	}
};