#include "header.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {	}
};

/*��ʵ��һ�����������һ�ö������Ƿ�Ϊ�����������
�������ĸ����ָ��TreeNode* root���뷵��һ��bool����������Ƿ�Ϊ�����������*/
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
