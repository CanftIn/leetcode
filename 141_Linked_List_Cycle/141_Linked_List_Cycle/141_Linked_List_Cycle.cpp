// 141_Linked_List_Cycle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

/**
* Definition for singly-linked list.
*/ 
struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;

	while (fast->next || fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ListNode *head = NULL;

	hasCycle(head);
    return 0;
}

