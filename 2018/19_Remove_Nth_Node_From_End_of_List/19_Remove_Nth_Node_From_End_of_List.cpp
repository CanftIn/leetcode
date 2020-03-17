#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = head, *cur = head, *fprev = dummy;
        while(cur != NULL && n > 0)
        {
            cur = cur->next;
            n--;
        }
        while(cur != NULL)
        {
            fprev = fprev->next;
            prev = prev->next;
            cur = cur->next;
        }
        fprev->next = prev->next;
        delete prev;
        return dummy->next;
    }
};