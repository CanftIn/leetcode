#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while(p->next != NULL && p->next->next != NULL)
        {
            if(p->next->val == p->next->next->val)
            {
                int samenum = p->next->val;
                while(p->next != NULL && p->next->val == samenum)
                {
                    p->next = p->next->next;
                }
            }
            else
                p = p->next;
        }
        return dummy->next;
    }
};