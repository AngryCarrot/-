#include "header.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
	bool isPalindrome(ListNode* pHead) {
		// write code here
		ListNode* middle = this->getMiddleNode(pHead);
		ListNode* p = middle;
		middle->next = this->reverseList(middle->next);
		ListNode nH(0);
		nH.next = pHead;
		ListNode* prev = pHead;
		ListNode* post = middle->next;
		while (post != nullptr)
		{
			if (post->val != prev->val)
			{
				return false;
			}
			post = post->next;
			prev = prev->next;
		}
		return true;
	}
private:
	ListNode* reverseList(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
		{
			return pHead;
		}
		ListNode* nHead = this->reverseList(pHead->next);
		pHead->next->next = pHead;
		pHead->next = nullptr;
		return nHead;
	}
	ListNode* getMiddleNode(ListNode* pHead)
	{
		ListNode* nH = new ListNode(0);
		nH->next = pHead;
		ListNode* slow = nH;
		ListNode* fast = nH;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		pHead = nH->next;
		delete nH;
		return slow;
	}
};

int main_isPalindrome()
{
	ListNode p1(1);
	ListNode p2(2);
	ListNode p3(2);
	ListNode p4(1);
	//ListNode p5(1);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	//p4.next = &p5;
	Palindrome p;
	cout << p.isPalindrome(&p1) << endl;
	return 0;
}