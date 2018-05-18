#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode *smallHead = new ListNode(0);
        ListNode *bigHead = new ListNode(0);
        ListNode *smalldummy = smallHead;
        ListNode *bigdummy = bigHead;
        while(head != NULL)
        {
            if(head->val < x)
            {
                ListNode *smalltemp = new ListNode(head->val);
                smallHead->next = smalltemp;
                smallHead = smallHead->next;
            }
            if(head->val >= x)
            {
                ListNode *bigtemp = new ListNode(head->val);
                bigHead->next = bigtemp;
                bigHead = bigHead->next;
            }
            head = head->next;
        }
        smallHead->next = bigdummy->next;
        return smalldummy->next;
    }
};