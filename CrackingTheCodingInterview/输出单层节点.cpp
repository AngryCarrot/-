#include "header.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {	}
};

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};

/*对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，
请返回一个链表ListNode，代表该深度上所有结点的值，
请按树上从左往右的顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。*/
class TreeLevel {
public:
	ListNode* getTreeLevel(TreeNode* root, int dep) {
		// write code here
		queue<TreeNode*> q;
		q.push(root);
		ListNode head(0);
		ListNode* cur = &head;
		while (!q.empty() && 0 != dep)
		{
			--dep;
			size_t length = q.size();
			for (size_t i = 0; i < length; i++)
			{
				TreeNode* p = q.front();
				q.pop();
				if (0 == dep)
				{
					ListNode* node = new ListNode(p->val);
					cur->next = node;
					cur = cur->next;					
				}
				if (nullptr != p->left)
				{
					q.push(p->left);
				}
				if (nullptr != p->right)
				{
					q.push(p->right);
				}
			}
		}
		return head.next;
	}
};