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