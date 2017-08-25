#include "header.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
public:
	ListNode* plusAB(ListNode* a, ListNode* b) {
		// write code here
		ListNode head(0);
		ListNode* p = &head;
		int acc = 0;
		while (nullptr != a || nullptr != b)
		{
			int sum = (nullptr != a ? a->val : 0) + (nullptr != b ? b->val : 0);
			int val = (sum + acc) % 10;
			acc = (sum + acc) / 10;
			ListNode* q = new ListNode(val);
			p->next = q;
			p = p->next;
			// ¿Ó
			if (nullptr != a)
			{
				a = a->next;
			}
			if (nullptr != b)
			{
				b = b->next;
			}
		}
		// ¿Ó
		if (0 != acc)
		{
			ListNode* q = new ListNode(acc);
			p->next = q;
		}
		return head.next;
	}
};

int main12()
{
	return 0;
}