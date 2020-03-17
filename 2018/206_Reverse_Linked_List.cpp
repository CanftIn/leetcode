#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode * reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode *prev = NULL;
	while (head != NULL)
	{
		ListNode *temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	return prev;
}

ListNode * makeList(ListNode *head)
{
	ListNode *a = new ListNode(3);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(1);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = NULL;
	return head;
}

int main()
{
	ListNode *head = makeList(new ListNode(4));
	ListNode *out = reverseList(head);

    return 0;
}

