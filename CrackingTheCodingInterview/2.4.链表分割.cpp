#include "header.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode less(0);
		ListNode greater(0);
		ListNode* pLess = &less;
		ListNode* pGreater = &greater;
		ListNode* pRunner = pHead;
		while (nullptr != pRunner)
		{
			if (pRunner->val < x)
			{
				pLess->next = pRunner;
				pLess = pLess->next;
				pRunner = pRunner->next;
				pLess->next = nullptr;
			}
			else
			{
				pGreater->next = pRunner;
				pGreater = pGreater->next;
				pRunner = pRunner->next;
				pGreater->next = nullptr;
			}
		}
		pLess->next = greater.next;
		return less.next;
	}
};

int main11()
{
	ListNode heads(6);
	ListNode h2(2);
	ListNode h3(8);
	heads.next = &h2;
	h2.next = &h3;

	Partition p;
	ListNode* r = p.partition(&heads, 9);
	cout << r->val << endl;

	return 0;
}