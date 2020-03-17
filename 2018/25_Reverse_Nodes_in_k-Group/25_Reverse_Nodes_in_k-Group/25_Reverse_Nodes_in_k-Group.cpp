#include <iostream>
#include <stdlib.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	static ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *guard = new ListNode(-1);
		guard->next = head;

		head = guard;
		for (;;)
		{
			int count = 0;
			ListNode *tmp = head->next;
			for (int i = 0; i < k; i++)
			{
				if (tmp == NULL)
					break;
				tmp = tmp->next;
				count++;
			}

			if (count < k)
				break;

			ListNode *first = head->next;
			for (int i = 0; i < k; ++i)
			{
				int idx = k - i - 1;
				ListNode *aim = first;
				while (idx--)
				{
					aim = aim->next;
				}
				head->next = aim;
				head = aim;
			}
			head->next = tmp;
		}

		return guard->next;
	}
};


void makeList(ListNode *node)
{
	ListNode *head = node;
	std::cout << head->val << "->";
	for (int i = 1; i <= 5; ++i)
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
	ListNode *newNode = Solution::reverseKGroup(node, 2);
	ListNode *temp = newNode;
	std::cout << temp->val << "->";
	for (int i = 0; i < 5; ++i)
	{
		temp = temp->next;
		std::cout << temp->val << "->";
	}
	return 0;
}