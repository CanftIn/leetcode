/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        for(ListNode *p = &dummy; l1 != NULL || l2  != NULL; p = p->next)
        {
            int val1 = l1 == NULL ? INT_MAX : l1->val;
            int val2 = l2 == NULL ? INT_MAX : l2->val;
            if(val1 <= val2)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};