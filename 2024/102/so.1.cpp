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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            vector<int> tmp;
            for (int i = que.size(); i > 0; --i) {
                root = que.front();
                que.pop();
                tmp.push_back(root->val);
                if (root->left != nullptr) que.push(root->left);
                if (root->right != nullptr) que.push(root->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};