#include "header.h"


struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
//extern struct ListNode;

class Remove {
public:
	bool removeNode(ListNode* pNode) {
		// write code here
		if (nullptr == pNode->next)
		{
			return false;
		}
		pNode->val = pNode->next->val;
		ListNode* p = pNode->next;		
		pNode->next = pNode->next->next;
		delete p;
		return true;
	}
};

int main10()
{
	return 0;
}