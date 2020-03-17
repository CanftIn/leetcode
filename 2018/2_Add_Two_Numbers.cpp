#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        int sum = 0;
        ListNode *p1 = l1, *p2 = l2;
        ListNode *cur = dummy;
        while(p1 != NULL || p2 != NULL)
        {
            if(p1 != NULL)
            {
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL)
            {
                sum += p2->val;
                p2 = p2->next;
            }
            cur->next = new ListNode(sum % 10);
            sum /= 10;
            cur = cur->next;
        }
        if(sum == 1)
        {
            cur->next = new ListNode(1);
        }
        return dummy->next;
    }
};