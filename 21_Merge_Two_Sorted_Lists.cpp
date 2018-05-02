#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;  
        if (!l2) return l1; 
        
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;
        
        return dummy->next;
    }
};

class Solution2 {  
public:  
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {  
        if(l1 == NULL) return l2;//返回较长的链表；  
        if(l2 == NULL) return l1;  
  
        if(l1->val < l2->val) {  
            l1->next = mergeTwoLists(l1->next, l2);  
            return l1;//跳到下一个节点  
        } else {  
            l2->next = mergeTwoLists(l2->next, l1);  
            return l2;//将短链表l1按顺序插进l2中。  
        }  
    }  
}; 