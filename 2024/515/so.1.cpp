/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int max_value = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                max_value = max(max_value, node->val);
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(max_value);
        }
        return res;
    }
};
