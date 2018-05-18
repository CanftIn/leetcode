#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *mNode = head;
        ListNode *nNode = head;
        ListNode *preM = dummy;
        
        for(int i = 1; i < m; ++i)
        {
            mNode = mNode->next;
            preM = preM->next;
        }
        for(int i = 1; i < n; ++i)
        {
           nNode = nNode->next;
        }
        while(mNode != nNode)
        {
            preM->next = mNode->next;
            mNode->next = nNode->next;
            nNode->next = mNode;
            mNode = preM->next;
        }
        return dummy->next;
    }
};