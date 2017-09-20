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

/*����һ�ö������������һ���㷨����������ĳһ��������н�������
�����������ĸ����ָ��TreeNode* root���Լ������Ͻ�����ȣ�
�뷵��һ������ListNode���������������н���ֵ��
�밴���ϴ������ҵ�˳�����ӣ���֤��Ȳ��������ĸ߶ȣ����Ͻ���ֵΪ�Ǹ������Ҳ�����100000��*/
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