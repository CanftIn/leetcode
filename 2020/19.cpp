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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        if(!head)  return head;
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for(int i=0; i<n;i++) {
            q=q->next;
        }
        while(q->next) {
           p= p->next;
           q= q->next;
        }
        p->next = p->next->next;
   
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};