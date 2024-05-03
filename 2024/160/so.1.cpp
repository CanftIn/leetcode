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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            if (pA == nullptr) {
                pA = headB;
            } else {
                pA = pA->next;
            }
            if (pB == nullptr) {
                pB = headA;
            } else {
                pB = pB->next;
            }
        }
        return pA;
    }
};
