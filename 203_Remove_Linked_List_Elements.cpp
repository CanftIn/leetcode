#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while(head != NULL)
        {
            if(head->val == val)
            {
                ListNode *temp = head->next;
                prev->next = temp;
                head = temp;
            }
            else
            {
                head = head->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};