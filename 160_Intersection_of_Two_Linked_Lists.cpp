#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *lA = headA;
        ListNode *lB = headB;
        int lengthA = 0, lengthB  = 0;
        while(lA != NULL)
        {
            lA = lA->next;
            lengthA++;
        }
        while(lB != NULL)
        {
            lB = lB->next;
            lengthB++;
        }
        int distance;
        if(lengthA > lengthB)
        {
            distance = lengthA - lengthB;
            while(distance != 0)
            {
                headA = headA->next;
                distance--;
            }
        }
        else
        {
            distance = lengthB - lengthA;
            while(distance != 0)
            {
                headB = headB->next;
                distance--;
            }
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};