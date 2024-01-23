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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* dummy = head;
        int carry = 0;
        while (l1 && l2) {
            int num = (l1->val + l2->val + carry) % 10;
            ListNode* node = new ListNode(num);
            head->next = node;
            head = node;

            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int num = (l1->val + carry) % 10;
            ListNode* node = new ListNode(num);
            head->next = node;
            head = node;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int num = (l2->val + carry) % 10;
            ListNode* node = new ListNode(num);
            head->next = node;
            head = node;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
        if (carry != 0) {
            ListNode* node = new ListNode(carry);
            head->next = node;
            head = node;
        }
        return dummy->next;
    }
};