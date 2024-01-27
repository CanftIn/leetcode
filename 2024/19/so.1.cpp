/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* findFromEnd(ListNode* head, int k) {
        ListNode* p1 = head;
        for (int i = 0; i < k; ++i) {
            p1 = p1->next;
        }
        ListNode* p2 = head;
        while (p1 != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* x = findFromEnd(dummy, n + 1);
        x->next = x->next->next;
        return dummy->next;
    }
};