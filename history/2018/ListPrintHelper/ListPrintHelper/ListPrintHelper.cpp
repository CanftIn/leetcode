#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* func(ListNode* head, int k)
{
	ListNode *tmp = nullptr;
	return tmp;
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
	ListNode *newNode = func(node, 2);
	ListNode *temp = newNode;
	std::cout << temp->val << "->";
	for (int i = 0; i < 5; ++i)
	{
		temp = temp->next;
		std::cout << temp->val << "->";
	}
	return 0;
}