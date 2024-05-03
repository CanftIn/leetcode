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
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* node1 = cur->next;
            ListNode* node2 = cur->next->next;

            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};
