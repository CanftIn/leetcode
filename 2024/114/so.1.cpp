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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;
        TreeNode* p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
    }
};