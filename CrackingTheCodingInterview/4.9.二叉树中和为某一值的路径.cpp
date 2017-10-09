#include "header.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<int> current;
		vector<vector<int>> result;
		this->FindPathHelper(root, expectNumber, current, result);
		return result;
	}
private:
	void FindPathHelper(TreeNode* root, int expectNumber, vector<int>& current, vector<vector<int>>& result)
	{
		if (nullptr == root)
		{
			return;
		}
		current.emplace_back(root->val);
		if (nullptr == root->left && nullptr == root->right)
		{
			if (root->val == expectNumber)
			{				
				result.emplace_back(current);
				current.pop_back();
				return;
			}
		}
		this->FindPathHelper(root->left, expectNumber - root->val, current, result);
		this->FindPathHelper(root->right, expectNumber - root->val, current, result);
		current.pop_back();
	}
};