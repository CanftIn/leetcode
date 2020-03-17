#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* swapPairs(ListNode* head) {
	ListNode **pp = &head, *a, *b;
	while ((a = *pp) && (b = a->next)) {
		a->next = b->next;
		b->next = a;
		*pp = b;
		pp = &(a->next);
	}
	return head;
}

void makeList(ListNode *node)
{
	ListNode *head = node;
	std::cout << head->val << "->";
	for (int i = 1; i < 5; ++i)
	{
		ListNode *temp = new ListNode(i);
		std::cout << temp->val << "->";
		head->next = temp;
		head = head->next;
	}
	std::cout << std::endl;
}

int main()
{
	ListNode *node = new ListNode(0);
	makeList(node);
	ListNode *newNode = swapPairs(node);
	ListNode *temp = newNode;
	std::cout << temp->val << "->";
	for (int i = 0; i < 5; ++i)
	{
		temp = temp->next;
		std::cout << temp->val << "->";
	}
	return 0;
}