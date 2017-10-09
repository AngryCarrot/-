#include "header.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {	}
};
//1-2-3-4-5-^
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (nullptr == pListHead || k < 0)
		{
			return nullptr;
		}
		ListNode* fast = pListHead;
		for (size_t i = 0; i < k; ++i)
		{
			if (nullptr == fast)
			{
				return nullptr;
			}
			else
			{
				fast = fast->next;
			}
		}
		ListNode* slow = pListHead;
		while (nullptr != fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main9()
{
	ListNode heads(1);
	ListNode h2(2);
	ListNode h3(3);
	ListNode h4(4);
	ListNode h5(5);
	heads.next = &h2;
	h2.next = &h3;
	h3.next = &h4;
	h4.next = &h5;

	Solution s;
	ListNode* r = s.FindKthToTail(&heads, 3);
	cout << r->val << endl;
	getchar();
	return 0;
}