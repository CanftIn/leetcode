#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return ;
        ListNode *temp = NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *l1 = head;
        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        ListNode *l2 = reverse(slow);
        merge(l1, l2);
    }
    
private:
    ListNode* reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while(head != NULL)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    void merge(ListNode *l1, ListNode *l2)
    {
        while(l1 != l2)
        {
            ListNode *n1 = l1->next;
            ListNode *n2 = l2->next;
            l1->next = l2;
            if(n1 == NULL) return ;
            l2->next = n1;
            l1 = n1;
            l2 = n2;
        }
    }
};