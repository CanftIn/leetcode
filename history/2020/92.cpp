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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* tail = head;
        int delta = n - m;
        while (m > 1) {
            prev = tail;
            tail = tail->next;
            --m;
        }
        while(delta > 0) {
            ListNode* next = tail->next;
            tail->next = next->next;
            next->next = prev->next;
            prev->next = next;
            --delta;
        }
        return dummy->next;
    }
};