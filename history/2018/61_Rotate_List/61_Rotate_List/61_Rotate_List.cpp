#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* rotateRight(ListNode* head, int k) {
	if (!head) return head;

	int len = 1;
	ListNode *newH, *tail;
	newH = tail = head;

	while (tail->next)
	{
		tail = tail->next;
		len++;
	}
	tail->next = head;

	if (k %= len)
	{
		for (auto i = 0; i<len - k; i++) tail = tail->next;
	}
	newH = tail->next;
	tail->next = NULL;
	return newH;
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
	ListNode *newNode = rotateRight(node, 2);
	ListNode *temp = newNode;
	std::cout << temp->val << "->";
	for (int i = 0; i < 5; ++i)
	{
		temp = temp->next;
		std::cout << temp->val << "->";
	}	
	return 0;
}