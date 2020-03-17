#include <iostream>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * my answer with error, but giving the thinking
     **/
    bool isPalindrome(ListNode* head) {
        if(head == NULL || !head->next) return true;
        stack<ListNode*> stack;
        ListNode *fast = head, *slow = head;
        int length = 0;
        while(fast != NULL && fast->next != NULL)
        {
            stack.push(slow);
            fast = fast->next->next;
            slow = slow->next;
            length++;
        }
        slow = slow->next;
        for(int i = 0; i < length; ++i)
        {
            ListNode *temp = stack.top();
            if(temp->val == slow->val)
            {
                stack.pop();
                slow = slow->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    // others
    bool isPalindrome_others(ListNode* head) {
        stack<int> stk {};
        auto p_node = head;
        
        while (p_node) {
            stk.push(p_node->val);
            
            p_node = p_node->next;
        }
        
        while (head) {
            if (head->val != stk.top() ) return false;
            
            stk.pop();
            head = head->next;
        }
        return true;
    }
};