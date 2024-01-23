/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
        ListNode* dummy = new ListNode(-1);
        ListNode* forward = dummy;
        int carry = 0;
        while (l1 || l2) {
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            int num = (l1_val + l2_val + carry) % 10;
            forward = new ListNode(num);
            forward = forward->next;
            carry = (l1_val + l2_val + carry) / 10;
            l1 = l1 ? l1 :l1->next;
            l2 = l2 ? l2 :l2->next;
        }
        if (carry == 1) {
            forward = new ListNode(carry);
        }
        return dummy->next;
    }
};
// @lc code=end

