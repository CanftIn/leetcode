#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> level_count;
        vector<vector<int>> res;
        stack<TreeNode*> stack;
        queue<TreeNode*> q;
        TreeNode *current = NULL;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty())
        {
            level_count.push_back(q.size());
            for(int i = 0; i < level_count[level_count.size() - 1]; ++i)
            {
                current = q.front();
                q.pop();
                stack.push(current);
                if(current->right != NULL)
                    q.push(current->right);
                if(current->left != NULL)
                    q.push(current->left);
            }
        }
        int level_size = level_count.size(); 
        res.resize(level_size);
        for(int i = res.size() - 1; i >= 0; --i)
        {
            for(int j = 0; j < level_count[i]; ++j)
            {
                current = stack.top();
                stack.pop();
                res[level_size - i - 1].push_back(current->val);
            }
        }
        return res;
    }
};