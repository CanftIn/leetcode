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
    void traverse(vector<int>& vec, TreeNode* root) {
        if (root == nullptr) return;
        traverse(vec, root->left);
        traverse(vec, root->right);
        vec.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == nullptr) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
