#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *temp = NULL, *prev = NULL;
        while(cur != NULL && cur->next != NULL)
        {
            if(cur->val <= cur->next->val)
            {
                cur = cur->next;
            }
            else
            {
                temp = cur->next;
                cur->next = temp->next;
                prev = dummy;
                while(prev->next->val <= temp->val)
                {
                    prev = prev->next;
                }
                temp->next = prev->next;
                prev->next = temp;
            }
        }
        return dummy->next;
    }
};