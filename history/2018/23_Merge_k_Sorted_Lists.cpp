#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode *p = lists[0];
        for(int i = 1; i < lists.size(); ++i)
            p = mergeTwoLists(p, lists[i]);
        return p;
    }
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 == NULL)
        {
            p->next = l2;
        }
        if(l2 == NULL)
        {
            p->next = l1;
        }
        return dummy->next;
    }
};